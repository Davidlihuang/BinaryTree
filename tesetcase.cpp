#include <iostream>
#include "binarytree.h"

int main()
{
	using namespace std;
	Bitree Tree;
	//create tree in pre order
	cout << "create treee in pre order" << endl;
	CreateTree(Tree);

	//traverse trees in recurve way
	cout << "\npre order traverse: ";
	PreOrderTraverse(Tree);
	cout<< "\nin order traverse: ";
	InOrderTraverse(Tree);
	cout << "\nAter order traverse: ";
	AftOrderTraverse(Tree);
	cout << endl;

	//traverse tree in non recurse way
	cout << "\nPreOrederTraverseNoRecurse:";
	PreOrederTraverseNoRecurse(Tree);
	cout << "\nInOrederTraverseNoRecurse:";
	InOrderTraverseNoRecurse(Tree);
	cout << "\nAftOrederTraverseNoRecurse:";
	AftOrderTraverseNoRecurse(Tree);
	cout << endl;

	cout << "\nLayerTraverseNoRecurse:";
	LayerTraverseNoRecurse(Tree);

	//左右孩子法实现先序遍历
	cout << "\nPreorderLrchildTraverse:";
	PreorderLrchildTraverse(Tree);
	cout << endl;

	//叶子结点
	cout << "\nget leaves in preorder:";
	TreeLeavesPreOrder(Tree);
	cout << "\nget leaves in inorder:";
	TreeLeavesInOrder(Tree);
	cout << "\nget leaves in postorder:" ;
	TreeLeavesAftOrder(Tree);
	cout << endl;

	//获取树的深度
	cout << "tree depth: "<<TreeDepth(Tree) << endl;
	return 0;
}