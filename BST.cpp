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

int BST::maxOfHeights(TNode *m, TNode *n){
    if (m==NULL){
        return n->height;
    }
    if (n==NULL){
        return m->height;
    }
    if (m->height > n->height){
        return m->height;
    }
    else{
        return n->height;
    }
}

void BST::setHeight(TNode *n){
    if (n->parent!=NULL){
        if (n->parent->height==maxOfHeights(n->parent->left,n->parent->right)+1||n->parent==NULL){
            return;
        }
        else{
            //cout << "else part"<<endl;
            n->parent->height += 1;
            setHeight(n->parent);
        }
    }
}

TNode* BST::find(string s){
}

void BST::printTreeIO(TNode *n){
    if (n==NULL){
        return;
    }
    else{
        printTreeIO(n->left);
        cout << n->data->phrase<<","<<n->height;
        cout << endl;
        printTreeIO(n->right);
    }
}

void BST::printTreePre(TNode *n){
    if (n==NULL){
        return;
    }
    else{
        cout << n->data->phrase<<","<<n->height;
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
        cout << n->data->phrase<<","<<n->height;
        cout << endl;
    }
}

TNode* BST::remove(string s){

}

TNode* BST::removeNoKids(TNode *tmp){

}

TNode* BST::removeOneKid(TNode *tmp, bool leftFlag){

}

