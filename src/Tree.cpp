/*
 * Tree.cpp
 *
 *  Created on: 12 Ιουλ 2016
 *      Author: Souvlakomanis
 */

#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

Tree::Tree() {
	root = 0;
}

Tree::~Tree() {}

bool Tree::IsEmpty(){
	return ((root) ? false : true);
}

//rotates right and return tree
Tree& Tree::rotateRight(TreeNode *&p){
	TreeNode *temp = p;
	p = p->left;
	temp->left = p->right;
	p->right = temp;
	return *this;
}

//rotates right and return tree
Tree& Tree::rotateLeft(TreeNode *&p){
	TreeNode *temp = p;
	p = p->right;
	temp->right = p->left;
	p->left = temp;
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
	/*
	while( i!=0 &&(
		(pointers[i-1]->left!=0 ? (pointers[i-1]->pi < pointers[i-1]->left->pi) : false) ||
		(pointers[i-1]->right!=0 ? (pointers[i-1]->pi < pointers[i-1]->right->pi) : false))) {
		if (pointers[i]->ei < pointers[i-1]->ei) { //if node is left child
			i--;
			//rotateRight(pointers[i]);
			TreeNode *temp = pointers[i];
			pointers[i] = pointers[i]->left;
			temp->left = pointers[i]->right;
			pointers[i]->right = temp;
		}else{
			i--;
			//rotateLeft(pointers[i]);
			TreeNode *temp;
			temp = pointers[i];
			pointers[i] = pointers[i]->right;
			temp->right = pointers[i]->left;
			pointers[i]->left = temp;

			if (i!=0) {
				if(pointers[i] == pointers[i-1]->left) pointers[i-1]->left =pointers[i];
				else pointers[i-1]->right =pointers[i];
			}
		}
	}
	root = pointers[0];
	return *this;
	*/
}

Tree& Tree::Delete(const int& p, const int& e){
	TreeNode *current = root;
	//current will point to the element we want to delete
	while(current!=0 && ((current->pi !=p)||(current->ei != e))){
		if(e < current->ei) current = current->left;
		else current = current->right;
	}
	if (current == 0) throw "Not Found";

	TreeNode *parent;
	while(current->right!=0 && current->left!=0){//untill current is node with 0 or 1 childs
		parent = current;
		//if the bigger is the left child,rotateRight
		if(current->left->pi > current->right->pi){
			rotateRight(current);
			current = current->right;
		}else{
			rotateLeft(current);
			current = current->left;
		}
	}

	TreeNode *child; //child of current
	if(current->left!=0) child = current->left;
	else child = current->right;

	//"skip" current
	if (current == root) root = child;
	else {
		if (current == parent->left) parent->left = child;
		else parent->right = child;
	}
	delete current;
	return *this;
}

int Tree::Find_second_next(int x){
	int temp = 0;
	//do inorder starting from root untill 2 items after x
	int y = 0;
	Find_second_next_InOrder(root, x, temp, y);
	return y;
}
//returns value at y
void Tree::Find_second_next_InOrder(TreeNode *p,const int& x, int& i,int& y){
	if(p!=0){
		Find_second_next_InOrder(p->left,x,i,y);
		if (i==0){
			if (p->ei == x)
				i=1;  //i=1 when we found it
		}else{
			i++;
			if (i==2+1){ //we passed 2 items while doing inorder
				y = p->ei;
				return;
			}
		}
		Find_second_next_InOrder(p->right,x,i,y);
	}
}

void Tree::Print_Between(int k1,int k2){
	cout << "Printing elements in [" << k1 << "," << k2 << "]:" << endl;
	Print_between_InOrder(root,k1,k2); //do inorder and print elements between k1,k2
}
void Tree::Print_between_InOrder(TreeNode *p,int k1,int k2){
	if (p!=0){
		Print_between_InOrder(p->left,k1,k2);
		if(p->ei >= k1 && p->ei <= k2)
			cout << p->ei << endl;
		Print_between_InOrder(p->right,k1,k2);
	}
}

void Tree::Print_with_higher_priority(int x){

}
















