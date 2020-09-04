#include "binarytree.h"

using namespace std;
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

//递归遍历树
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
//非递归遍历树
void PreOrederTraverseNoRecurse(Bitree T)
{
	stack<TreeNode*> s;
	TreeNode* p = T;
	while (p != nullptr || !s.empty()) {
		while (p != nullptr) {
			cout << p->data << " ";
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}
void InOrderTraverseNoRecurse(Bitree T)
{
	stack<Bitree> s;
	Bitree p = T;
	while (p != nullptr || !s.empty()) {
		while (p != nullptr) {
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty()) {
			p = s.top();
			cout << p->data << " ";
			s.pop();
			p = p->rchild;
		}
	}
}
void AftOrderTraverseNoRecurse(Bitree T)
{
	stack<Bitree> s;
	Bitree p = T;
	while (p != nullptr || !s.empty()) {
		while (p != nullptr) {
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}

//层遍历树
void LayerTraverseNoRecurse(Bitree T)
{
	//1、根节点入队 2、根节点出队，并将其孩子结点入队  3、出队并将队首元素孩子入队
	if (T) {
		Bitree p = T;
		queue<Bitree> Que;
		Que.push(p);
		while (!Que.empty()) {
			p = Que.front();
			cout << p->data << " ";
			Que.pop();
			if (p->lchild) Que.push(p->lchild);
			if (p->rchild) Que.push(p->rchild);
		}
	}
}

