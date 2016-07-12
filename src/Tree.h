/*
 * Tree.h
 *
 *  Created on: 12 Ιουλ 2016
 *      Author: Souvlakomanis
 */

#ifndef TREE_H_
#define TREE_H_
#include "TreeNode.h"
class TreeNode;

class Tree {
public:
	Tree();
	~Tree();
	Tree& rotateRight(TreeNode *p, TreeNode *pp);
	Tree& rotateLeft(TreeNode *p, TreeNode *pp);
	Tree& Insert(const int& p, const int& e);
	bool IsEmpty();
private:
	TreeNode* root;
};

#endif /* TREE_H_ */
