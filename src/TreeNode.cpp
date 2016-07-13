#include "TreeNode.h"

TreeNode::TreeNode() {
	left = right = 0;
	ei = pi = 0;
}

TreeNode::TreeNode(const int& p, const int& e){
	left = right = 0;
	pi = p;
	ei = e;
}

TreeNode::TreeNode(const int& p, const int& e, TreeNode *l, TreeNode *r){
	left = l;
	right = r;
	pi = p;
	ei = e;
}


