/*
 * Tree.cpp
 *
 *  Created on: 12 Ιουλ 2016
 *      Author: Souvlakomanis
 */

#include "Tree.h"
#include "TreeNode.h"
#include <iostream>

Tree::Tree() {
	root = 0;
}

Tree::~Tree() {}

bool Tree::IsEmpty(){
	return ((root) ? false : true);
}

//given a node p and its parent, rotates right and return tree
Tree& Tree::rotateRight(TreeNode *p, TreeNode *pp){
	if (p == pp->left){
		pp->left = p->left;
		p->left = p->left->right;
		pp->left->right = p;
	}else{
		pp->right = p->left;
		p->left = p->left->right;
		pp->right->right = p;
	}
	return *this;
}

//given a node p and its parent, rotates left and return tree
Tree& Tree::rotateLeft(TreeNode *p, TreeNode *pp){
	if (p == pp->left){
		pp->left = p->right;
		p->right = p->right->left;
		pp->left->left = p;
	}else{
		pp->right = p->right;
		p->right = p->right->left;
		pp->right->left = p;
	}
	return *this;
}

Tree& Tree::Insert(const int& p, const int& e){
	const int MAXHEIGHT = 30; //max height of inserted node=30
	TreeNode *pointers[MAXHEIGHT]; //an array of treenode pointers (will be used to go up)
	pointers[0] = root;

	int i = 0;
	//pointers[i] will point to right place(according to ei as BST) for new node
	while(pointers[i]!=0){
		if (e < pointers[i]->ei) //move to left or right child?
			pointers[i+1] = pointers[i]->left;
		else if ( e > pointers[i]->ei)
			pointers[i+1] = pointers[i]->right;
		else throw "Bad Input! Already exists.";
		i++;
	}//pointers[i] points to null,pointers[i-1] to leaf

	TreeNode *node = new TreeNode(p,e);  //make new node to be inserted with given values and insert it as last treenode
	if (!IsEmpty()) {
		if (e < pointers[i-1]->ei) {
			pointers[i-1]->left = node;
			pointers[i] = node;
		}
		else {
			pointers[i-1]->right = node;
			pointers[i] = node;
		}
	}else{ //if its empty,insert it as root and return
		root = node;
		return *this;
	}

	//pointers[i] is now the leaf,now we go backwards
	//doing rotations while the tree is not max tree
	while(pointers[i-1]->pi < pointers[i-1]->left->pi || pointers[i-1]->pi < pointers[i-1]->right->pi){
		if (pointers[i]->ei < pointers[i-1]->ei) { //if node is left child
			i--;
			rotateRight(pointers[i], pointers[i-1]);
		}else{
			i--;
			rotateLeft(pointers[i], pointers[i-1]);
		}
	}
	return *this;
}




