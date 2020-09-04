#include <iostream>
#include "binarytree.h"

int main()
{
	using namespace std;
	Bitree Tree;
	//create tree in pre order
	cout << "create treee in pre order" << endl;
	CreateTree(Tree);

	//treaver tree 
	cout << "\npre order traverse: ";
	PreOrderTraverse(Tree);
	cout<< "\nin order traverse: ";
	InOrderTraverse(Tree);
	cout << "\nAter order traverse: ";
	AftOrderTraverse(Tree);
	cout << "\nPreOrederTraverseNoRecurse:";
	PreOrederTraverseNoRecurse(Tree);
	cout << "\nInOrederTraverseNoRecurse:";
	InOrderTraverseNoRecurse(Tree);

	cout << "\nLayerTraverseNoRecurse:";
	LayerTraverseNoRecurse(Tree);

	//左右孩子法实现先序遍历
	cout << "\nPreorderLrchildTraverse:";
	PreorderLrchildTraverse(Tree);

	//叶子结点
	cout << "\nget leaves:";
	TreeLeavesPreOrder(Tree);
	cout << "\nget leaves:";
	TreeLeavesInOrder(Tree);
	cout << "\nget leaves:" ;
	TreeLeavesAftOrder(Tree);
	cout << endl;
	cout << "tree depth: "<<TreeDepth(Tree) << endl;
	return 0;
}