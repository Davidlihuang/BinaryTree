#pragma once
#ifndef BITNARYTREE_H_
#define BITNARYTREE_H_
#include <iostream>
#include <stack>
#include <queue>

typedef struct TreeNode* Bitree;
typedef char ElemType;
struct TreeNode
{
	ElemType data;
	TreeNode* lchild;
	TreeNode* rchild;
};
//������
void CreateTree(Bitree& T);
//������
void DestroyTree(Bitree& T);

//�ݹ������
void PreOrderTraverse(Bitree T);
void InOrderTraverse(Bitree T);
void AftOrderTraverse(Bitree T);

//�ǵݹ������
void PreOrederTraverseNoRecurse(Bitree T);
void InOrderTraverseNoRecurse(Bitree T);
void AftOrderTraverseNoRecurse(Bitree T);
void LayerTraverseNoRecurse(Bitree T);
void PreorderLrchildTraverse(Bitree T);

//���Ҷ�ӽ��
void TreeLeavesPreOrder(Bitree T);
void TreeLeavesInOrder(Bitree T);
void TreeLeavesAftOrder(Bitree T);

//�������
int TreeDepth(Bitree T);
#endif // !BITNARYTREE_H_
