/*
 * TNode.cpp
 *
 *  Created on: Oct 25, 2020
 *      Author: bryan
 */


#include <iostream>
#include <string>
#include "TNode.hpp"
using namespace std;

TNode::TNode(string s) {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	balance = 0;
	data = new Phrase(s);
}
TNode::TNode() {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	balance = 0;
	data = new Phrase();
}
TNode::~TNode(){
	cout <<"Deleting "<<data->phrase<<endl;
}
void TNode::printNode() {
	cout << data->phrase<<","<<height<<endl;
}

