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
void Tree::rotateRight(TreeNode *&p){
	TreeNode *temp = p;
	p = p->left;
	temp->left = p->right;
	p->right = temp;
}

//rotates right and return tree
void Tree::rotateLeft(TreeNode *&p){
	TreeNode *temp = p;
	p = p->right;
	temp->right = p->left;
	p->left = temp;
}

Tree& Tree::Insert(const int& p, const int& e){
	if(!IsEmpty()) Insert_Travel(root, p, e);
	else{
		TreeNode *node = new TreeNode(p,e);
		root = node;
	}
	return *this;
}
void Tree::Insert_Travel(TreeNode *&current, int p, int e){
	if(e < current->ei){
		if(current->left !=0){
			Insert_Travel(current->left, p, e);
			if(current->pi < current->left->pi) rotateRight(current);
		}else{
			TreeNode *node = new TreeNode(p,e);
			current->left = node;
			if(current->pi < p) rotateRight(current);
		}
	}else if(e > current->ei){
		if(current->right !=0){
			Insert_Travel(current->right, p, e);
			if(current->pi < current->right->pi) rotateLeft(current);
		}else{
			TreeNode *node = new TreeNode(p,e);
			current->right = node;
			if(current->pi < p) rotateLeft(current);
		}
	}else{
		throw "Already exists";
	}
}

Tree& Tree::Delete(const int& p, const int& e){
	TreeNode *current = root; //current ειναι ο κομβος που διασχιζουμε μεχρι να φτασουμε στον κομβο που θελουμε να διαγραψουμε
	TreeNode *pcurrent = 0; //pcurrent ειναι ο πατερας του current
	TreeNode *temp; //προσωρινος κομβος
	while(current!=0 && (current->ei!=e || current->pi!=p)){//αν current!=0, σημαινει οτι δεν βρεθηκε το στοιχειο. Αν current->ei!=e || current->pi!=p, τοτε ο κομβος που πρεπει να διαγραψουμε βρεθηκε
		if(e<current->ei){
			pcurrent = current;
			current = current->left; //πηγαινε στο αριστερο παιδι
		}else if(e>current->ei){
			pcurrent = current;
			current = current->right; // πηγαινε στο δεξι παιδι
		}
	}
	if (current==0) throw("To stoixeio afto den yparxei"); //δεν υπαρχει το στοιχειο
	while(current->left!=0 && current->right!=0){ //ο κομβος που πρεπει να διαγραφει,υποβιβαζεται συνεχως στο δεντρο με περιστροφες, μεχρι να γινει φυλλο
		if((current->left)->pi > (current->right)->pi){ //η προτεραιοτητα του αριστερου κομβου μεγαλυτερη απο την προτεραιοτητα του δεξιου κομβου
			temp = current->left; //αποθηκευουμε το παιδι με τον οποιο πρεπει να γινει η περιστροφη με το current
			rotateRight(current);
			pcurrent->left = temp; //ενωνουμε τον πρωην γονεα του current με το temp
			pcurrent = temp; // ο current εχει πλεον νεο γονεα
		}
		else{ //η προτεραιοτητα του δεξιου κομβου μεγαλυτερη απο την προτεραιοτητα του αριστερου κομβου
			temp = current->right;
			rotateLeft(current);
			pcurrent->right = temp;
			pcurrent = temp;
			}
	}
	delete current; //ο κομβος πλεον εγινε φυλλο. Τωρα μπορουμε να τον διαγραψουμε ευκολα
	return *this;
}



int Tree::Find_second_next(int x){
	if (!IsEmpty()){
		int temp = 0;
		//do inorder starting from root untill 2 items after x
		int y = 0;
		Find_second_next_InOrder(root, x, temp, y); //if not found returns 0 to y
		return y;
	}else throw "Tree is Empty";
}
//returns value at y
void Tree::Find_second_next_InOrder(TreeNode *p,const int& x, int& i, int& y){
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

void Tree::Print_Between(int k1, int k2){
	if(!IsEmpty()){
		//searching on binary tree for the first element between k1,k2
		TreeNode *current = root;
		while (current->ei < k1 || current->ei > k2){ //while is outside [k1,k2]
			if(k1 < current->ei) current = current->left;
			else current = current->right;
		}
		cout << "Printing ei elements in [" << k1 << "," << k2 << "]:" << endl;
		Print_between_InOrder(current,k1,k2); //do inorder on current's subtree and print elements between k1,k2
	}else cout << "Tree is empty";
}
void Tree::Print_between_InOrder(TreeNode *p, int k1, int k2){
	if (p!=0){
		Print_between_InOrder(p->left,k1,k2);
		if(p->ei >= k1 && p->ei <= k2)
			cout << p->ei << endl;
		else if (p->ei > k2){ //if current ei is bigger than k2, no need to travel more
			return;
		}
		Print_between_InOrder(p->right,k1,k2);
	}
}

void Tree::Print_with_higher_priority(int x){
	if (!IsEmpty()){
		cout << "Printing pi elements bigger than " << x << endl;
		Print_with_higher_priority_PreOrder(root,x); //travel through all pi elements
	}else cout << "Tree is empty";
}
void Tree::Print_with_higher_priority_PreOrder(TreeNode *p, int x){
	if(p!=0){
		if(p->pi > x){
			cout << p->pi << endl;
		}else{ //if current pi is less than x, no need to go on subtrees so skip them
			return;
		}
		Print_with_higher_priority_PreOrder(p->left, x);
		Print_with_higher_priority_PreOrder(p->right, x);
	}
}




/*Tree& Tree::Delete(const int& p, const int& e){
	TreeNode *current = root;
	TreeNode *parent = 0;
	//current will point to the element we want to delete
	while(current!=0 && ((current->pi !=p)||(current->ei != e))){
		parent = current;
		if(e < current->ei) current = current->left;
		else current = current->right;
	}
	if (current == 0) throw "Not Found";

	TreeNode *temp;
	while(current->right!=0 && current->left!=0){//untill current is node with 0 or 1 childs
		parent = current;
		//if the bigger is the left child,rotateRight
		if(current->left->pi > current->right->pi){
			//rotateRight(current);
			temp = current;
			current = current->left;
			temp->left = current->right;
			current->right = temp;

			current = current->right;
		}else{
			//rotateLeft(current);
			temp = current;
			current = current->right;
			temp->right = current->left;
			current->left = temp;

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
} */
