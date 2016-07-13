#ifndef TREE_H_
#define TREE_H_
#include "TreeNode.h"
class TreeNode;

class Tree {
	public:
		Tree();
		~Tree();
		bool IsEmpty();
		Tree& Insert(const int& p, const int& e);
		Tree& Delete(const int& p, const int& e);

		int Find_second_next(int x);
		void Print_Between(int k1, int k2);
		void Print_with_higher_priority(int x);

	private:
		TreeNode* root;
		void Insert_Travel(TreeNode *&current, int p, int e);
		void rotateRight(TreeNode *&p);
		void rotateLeft(TreeNode *&p);
		void Find_second_next_InOrder(TreeNode *p,const int& x, int& i, int& y);
		void Print_between_InOrder(TreeNode *p, int k1,int k2);
		void Print_with_higher_priority_PreOrder(TreeNode *p, int x);
};

#endif /* TREE_H_ */
