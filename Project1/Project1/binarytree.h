#pragma once
#ifndef BITNARYTREE_H_
#define BITNARYTREE_H_
#include <iostream>

using namespace std;
typedef struct TreeNode* Bitree;
typedef char ElemType;
struct TreeNode
{
	ElemType data;
	TreeNode* lchild;
	TreeNode* rchild;
};
//创建树
void CreateTree(Bitree& T)
{
	ElemType ch;
	cin >> ch;
	//if (ch != '\n') {
		if (ch == '#') {
			T = nullptr;
		}
		else {
			T = new TreeNode;
			if (T == nullptr) exit(OVERFLOW);
			T->data = ch;
			CreateTree(T->lchild);
			CreateTree(T->rchild);
		}
	//}
}
//销毁树
void DestroyTree(Bitree& T);

//遍历树
void PreOrderTraverse(Bitree T)
{
	if (T != nullptr) {
		cout << T->data << " ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(Bitree T)
{
	if (T != nullptr) {
		PreOrderTraverse(T->lchild);
		cout << T->data << " ";
		PreOrderTraverse(T->rchild);
	}
}
void AftOrderTraverse(Bitree T)
{
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
	cout << T->data << " ";
}

#endif // !BITNARYTREE_H_
