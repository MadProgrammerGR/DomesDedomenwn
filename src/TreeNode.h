#ifndef TREENODE_H_
#define TREENODE_H_
#include "Tree.h"

class TreeNode {
friend class Tree;
	public:
		TreeNode();
		TreeNode(const int& p, const int& e);
		TreeNode(const int& p, const int& e, TreeNode *l, TreeNode *r);
		int ei;
		int pi;
		TreeNode *left; //aristero paidi
		TreeNode *right; //de3i paidi
	private:
};

#endif /* TREENODE_H_ */
