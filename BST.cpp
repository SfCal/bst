/*
 * BST.cpp
 *
 *  Created on: Oct 25, 2020
 *      Author: bryan
 */
#include "BST.hpp"
#include <iostream>
#include <string>
using namespace std;


BST::BST() {
    root = NULL;
}
BST::BST(string s) {
    root = new TNode(s);
}

void BST::printTreeIO() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        cout << endl<<"Printing In Order:" <<endl;
        printTreeIO(root);
    }
}


void BST::printTreePre() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        cout << endl<<"Printing PreOrder:" <<endl;
        printTreePre(root);
    }
}


void BST::printTreePost() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        cout << endl<<"Printing PostOrder:" <<endl;
        printTreePost(root);
    }
}


void BST::clearTree() {
    if (root == NULL) {
        cout << "Tree already empty" << endl;
    }
    else {
        cout << endl << "Clearing Tree:" << endl;
        clearTree(root);
        root = NULL;
    }
}
void BST::clearTree(TNode *tmp) {
    if (tmp == NULL) {
        return;
    }
    else {
        clearTree(tmp->left);
        clearTree(tmp->right);
        tmp->printNode();
        delete(tmp);
    }
}

bool BST::insert(string s){
    TNode *temp;
    if (root==NULL){
        root = new TNode(s);
    }
    else{
        temp = root;
        while (temp!=NULL){
            if (s<temp->data->phrase){
                if (temp->left==NULL){
                    temp->left = new TNode(s);
                    temp->left->parent = temp;
                    setHeight(temp->left);
                    setBalance(temp->left);
                    return true;
                }
                else{
                    temp = temp->left;
                }
            }
            else if (s>temp->data->phrase){
                if (temp->right==NULL){
                    temp->right = new TNode(s);
                    temp->right->parent = temp;
                    setHeight(temp->right);
                    setBalance(temp->right);
                    return true;
                }
                else{
                    temp = temp->right;
                }
            }
            else{
                return false;
            }
        }
    }
}

void BST::setBalance(TNode *n){
    if (n->parent!=NULL){
        if(n->left==NULL && n->right!=NULL) {
            n->balance= 0 - n->right->height;
        }
        else if(n->left!=NULL && n->right==NULL) {
            n->balance= n->left->height - 0;
        }
        else if(n->left!=NULL && n->right!=NULL){
            n->balance = n->left->height - n->right->height;
        }
        else {
            n->balance = 0;
        }
        setBalance(n->parent);
    }
}

int BST::maxOfHeights(TNode *m, TNode *n){
    if (m==NULL&&n==NULL){
        //cout<<"no children"<<endl;
        return 0;
    }
    else if (m==NULL){
        return n->height;
    }
    else if (n==NULL){
        return m->height;
    }
    else if (m->height > n->height){
        return m->height;
    }
    else{
        return n->height;
    }
}

void BST::setHeight(TNode *n){
    if (n->parent!=NULL){
        if (n->parent->height==maxOfHeights(n->parent->left,n->parent->right)+1){
            return;
        }
        else{
            //cout << "else part"<<endl;
            n->parent->height=maxOfHeights(n->parent->left,n->parent->right)+1;
            setHeight(n->parent);
        }
    }
}

void BST::setHeightForRemove(TNode *n){
    if (n!=NULL){
        if (n->height==maxOfHeights(n->left, n->right)+1){
            return;
        }
        else{
            n->height=maxOfHeights(n->left, n->right)+1;
            setHeightForRemove(n->parent);
        }
    }
}


TNode* BST::find(string s){
    TNode *temp = root;
    while (temp!=NULL){
        if (temp->data->phrase==s){
            return temp;
        }
        else if (s>temp->data->phrase){
            temp = temp->right;
        }
        else if (s<temp->data->phrase){
            temp = temp->left;
        }
    }
    return NULL;
}

void BST::printTreeIO(TNode *n){
    if (n==NULL){
        return;
    }
    else{
        printTreeIO(n->left);
        cout << n->data->phrase<<","<<n->height<<","<<n->balance;
        cout << endl;
        printTreeIO(n->right);
    }
}

void BST::printTreePre(TNode *n){
    if (n==NULL){
        return;
    }
    else{
        cout << n->data->phrase<<","<<n->height<<","<<n->balance;
        cout << endl;
        printTreePre(n->left);
        printTreePre(n->right);
    }
}

void BST::printTreePost(TNode *n){
    if (n==NULL){
        return;
    }
    else{
        printTreePost(n->left);
        printTreePost(n->right);
        cout << n->data->phrase<<","<<n->height<<","<<n->balance;
        cout << endl;
    }
}

TNode* BST::remove(string s){
    TNode *tmp = find(s);
    TNode *tempRoot = find(s);
    TNode *tmpParent = NULL;
    if (tmp->left==NULL&&tmp->right==NULL){
        tmpParent=tmp->parent;
        removeNoKids(tmp);
        setHeightForRemove(tmpParent);
    }
    else if (tmp->left==NULL&&tmp->right!=NULL){
        tmpParent=tmp->parent;
        removeOneKid(tmp,false);
        setHeightForRemove(tmpParent);
    }
    else if (tmp->left!=NULL&&tmp->right==NULL){
        tmpParent=tmp->parent;
        removeOneKid(tmp,true);
        setHeightForRemove(tmpParent);
    }
    else if (tmp->left!=NULL&&tmp->right!=NULL){
        tmp=tmp->left;
        while (tmp->right!=NULL){
            tmp=tmp->right;
        }
        tempRoot->data->phrase=tmp->data->phrase;
        if (tmp->left==NULL){
            tmpParent=tmp->parent;
            removeNoKids(tmp);
            setHeightForRemove(tmpParent);
        }
        else if (tmp->left!=NULL){
            tmpParent=tmp->parent;
            removeOneKid(tmp,true);
            setHeightForRemove(tmpParent);
        }
    }
}



TNode* BST::removeNoKids(TNode *tmp){
    TNode *removedNode = tmp;
    if (tmp==tmp->parent->left){
        tmp->parent->left = NULL;
    }
    else if (tmp==tmp->parent->right){
        tmp->parent->right = NULL;
    }
    delete tmp;
    return removedNode;
}

TNode* BST::removeOneKid(TNode *tmp, bool leftFlag){
    TNode *removedNode = tmp;
    if (leftFlag==true){
        tmp->left->parent=tmp->parent;
        if (tmp==tmp->parent->right){
            tmp->parent->right=tmp->left;
        }
        else if (tmp==tmp->parent->left){
            tmp->parent->left=tmp->left;
        }
    }
    else if (leftFlag==false){
        tmp->right->parent=tmp->parent;
        if (tmp==tmp->parent->left){
            tmp->parent->left=tmp->right;
        }
        else if (tmp==tmp->parent->right){
            tmp->parent->right=tmp->right;
        }
    }
    delete tmp;
    return removedNode;
}

