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
		bool IsEmpty();
		Tree& rotateRight(TreeNode *&p);
		Tree& rotateLeft(TreeNode *&p);
		Tree& Insert(const int& p, const int& e);
		Tree& Delete(const int& p, const int& e);

		int Find_second_next(int x);
		void Print_Between(int k1,int k2);
		void Print_with_higher_priority(int x);

	private:
		TreeNode* root;
		void Find_second_next_InOrder(TreeNode *p,const int& x, int& i,int& y);
		void Print_between_InOrder(TreeNode *p,int k1,int k2);
};

#endif /* TREE_H_ */
