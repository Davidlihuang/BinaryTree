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
//创建树
void CreateTree(Bitree& T);
//销毁树
void DestroyTree(Bitree& T);

//递归遍历树
void PreOrderTraverse(Bitree T);
void InOrderTraverse(Bitree T);
void AftOrderTraverse(Bitree T);

//非递归遍历树
void PreOrederTraverseNoRecurse(Bitree T);
void InOrderTraverseNoRecurse(Bitree T);
void AftOrderTraverseNoRecurse(Bitree T);
void LayerTraverseNoRecurse(Bitree T);
void PreorderLrchildTraverse(Bitree T);

//输出叶子结点
void TreeLeavesPreOrder(Bitree T);
void TreeLeavesInOrder(Bitree T);
void TreeLeavesAftOrder(Bitree T);

//树的深度
int TreeDepth(Bitree T);
#endif // !BITNARYTREE_H_
