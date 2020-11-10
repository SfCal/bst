/*
 * TNode.hpp
 *
 *  Created on: Oct 25, 2020
 *      Author: bryan
 */

#ifndef TNODE_HPP_
#define TNODE_HPP_
#include <iostream>
#include "Phrase.hpp"
#include <string>
using namespace std;

class TNode{
	friend class BST;
	TNode *left;
	TNode *right;
	TNode *parent;
	Phrase *data;
	int height;
	int balance;
public:
	TNode(string s);
	TNode();
	~TNode();
	void printNode();
};



#endif /* TNODE_HPP_ */
