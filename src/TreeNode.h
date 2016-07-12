/*
 * TreeNode.h
 *
 *  Created on: 12 Ιουλ 2016
 *      Author: Souvlakomanis
 */

#ifndef TREENODE_H_
#define TREENODE_H_
#include "Tree.h"

class TreeNode {
friend class Tree;
public:
	TreeNode();
	TreeNode(const int& p, const int& e);
	TreeNode(const int& p, const int& e, TreeNode *l, TreeNode *r);
private:
	int pi;
	int ei;
	TreeNode *left; //aristero paidi
	TreeNode *right; //de3i paidi
};

#endif /* TREENODE_H_ */
