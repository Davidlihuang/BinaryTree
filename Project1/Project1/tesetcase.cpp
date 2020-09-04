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
	return 0;
}