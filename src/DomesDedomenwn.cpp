#include "Tree.h"
#include <iostream>
using namespace std;

int main() {
	Tree tree;

	/*//dentro sto sxhma a)
	tree.Insert(52,29);
	tree.Insert(47,13);
	tree.Insert(45,39);
	tree.Insert(42,10);
	tree.Insert(36,24);
	tree.Insert(30,32);
	tree.Insert(14,7);
	tree.Insert(2,11);
	tree.Insert(5,16);
	tree.Insert(15,23);
	tree.Insert(8,27);
	tree.Insert(21,4);
	tree.Insert(34,12);
	tree.Insert(33,19);
	tree.Insert(26,28);
	tree.Insert(11,30);
	tree.Insert(19,34);
	*/

	//tree.Print_with_higher_priority(32);

	//tree.Print_Between(24,30);

	//cout << tree.Find_second_next(11) << endl;
	//cout << tree.Find_second_next(19) << endl;
	//cout << tree.Find_second_next(34) << endl;

	//tree.Delete(47,13);

	tree.Insert(10,20);
	tree.Insert(1,1);
	tree.Insert(5,15);
	tree.Insert(3,18);
	tree.Delete(5,15);
	/*int answer = 0;
	do{
		cout << "===================================" << endl;
		cout << "Which function to do? (-1 for exit)" << endl;
		cout << "1. Insert(int p,int e)" << endl;
		cout << "2. Delete(int p,int e)" << endl;
		cout << "3. Find_second_next(int x)" << endl;
		cout << "4. Print_Between(int k1, int k2)" << endl;
		cout << "5. Print_with_higher_priority(int x)" << endl;
		cout << "====================================" << endl;
		cin >> answer;

		int x,k1,k2,count,p,e;
		switch(answer){
		case 1:
			cout << "How many times?" << endl;
			cin >> count;
			for (int i=0;i<count;i++){
				cout << "Value of p?" << endl;
				cin >> p;
				cout << "Value of e?" << endl;
				cin >> e;
				cout << "===========" << endl;
				tree.Insert(p,e);
			}
			break;
		case 2:
			cout << "How many times?" << endl;
			cin >> count;
			for (int i=0;i<count;i++){
				cout << "Value of p?" << endl;
				cin >> p;
				cout << "Value of e?" << endl;
				cin >> e;
				cout << "===========" << endl;
				tree.Delete(p,e);
			}
			break;
		case 3:
			cout << "Give number x:" << endl;
			cin >> x;
			cout << tree.Find_second_next(x) << endl;
			break;
		case 4:
			cout << "Give number k1:" << endl;
			cin >> k1;
			cout << "Give number k2:" << endl;
			cin >> k2;
			tree.Print_Between(k1,k2);
			break;
		case 5:
			cout << "Give number x:" << endl;
			cin >> x;
			tree.Print_with_higher_priority(x);
			break;
		}
	}while(answer!=-1);

	cout << "Byebye!" << endl;
	*/

	return 0;
}
