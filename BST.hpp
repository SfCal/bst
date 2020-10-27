/*
 * BST.hpp
 *
 *  Created on: Oct 25, 2020
 *      Author: bryan
 */

#ifndef BST_HPP_
#define BST_HPP_
#include <string>
using namespace std;
#include "TNode.hpp"

class BST {
	TNode *root;

public:
	BST();
	BST(string s);
	bool insert(string s);
	TNode *find(string s);
	int maxOfHeights(TNode *m, TNode *n);
	void printTreeIO();
	void printTreeIO(TNode *n);
	void printTreePre();
	void printTreePre(TNode *n);
	void printTreePost();
	void printTreePost(TNode *n);
	void clearTree();
	void clearTree(TNode *tmp);
	TNode *removeNoKids(TNode *tmp);
	TNode *removeOneKid(TNode *tmp, bool leftFlag);
	TNode *remove(string s);
	void setHeight(TNode *n);
};



#endif /* BST_HPP_ */
