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
		InOrderTraverse(T->lchild);
		cout << T->data << " ";
		InOrderTraverse(T->rchild);
	}
}
void AftOrderTraverse(Bitree T)
{
	if (T != nullptr) {
		AftOrderTraverse(T->lchild);
		AftOrderTraverse(T->rchild);
		cout << T->data << " ";
	}
	
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

	Bitree top = nullptr;
	Bitree cur = T;
	Bitree pre = nullptr;

	if (T != nullptr) {
		while (cur || !s.empty()) {
			while (cur) {
				s.push(cur);
				cur = cur->lchild;
			}
			top = s.top();
			if (top->rchild == nullptr || top->rchild == pre) {
				cout << top->data << " ";
				pre = top;
				s.pop();
			}
			else {
				cur = top->rchild;
			}
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

//左右孩子法实现先序遍历
void PreorderLrchildTraverse(Bitree T)
{
	if (T) {
		stack<Bitree> s;
		Bitree p = T;
		s.push(p);
		while (!s.empty())
		{
			p = s.top();
			cout << p->data << " ";
			s.pop();
			if (p->lchild) s.push(p->rchild);
			if (p->rchild) s.push(p->lchild);
		}
	}
}

//输出叶子结点
void TreeLeavesPreOrder(Bitree T) {
	if (T) {
		if (T->lchild == nullptr && T->rchild == nullptr) {
			cout << T->data << " ";
		}
		TreeLeavesPreOrder(T->lchild);
		TreeLeavesPreOrder(T->rchild);
	}
}
void TreeLeavesInOrder(Bitree T){
	if (T) {
		TreeLeavesPreOrder(T->lchild);
		if (T->lchild == nullptr && T->rchild == nullptr) {
			cout << T->data << " ";
		}
		TreeLeavesPreOrder(T->rchild);
	}
}
void TreeLeavesAftOrder(Bitree T) {
	if (T) {
		if (T->lchild == nullptr && T->rchild == nullptr) {
			cout << T->data << " ";
		}
		TreeLeavesPreOrder(T->lchild);
		TreeLeavesPreOrder(T->rchild);
		if (T->lchild == nullptr && T->rchild == nullptr) {
			cout << T->data << " ";
		}
	}
}

//获取树的深度
int TreeDepth(Bitree T) {

	if (T) {
		int hl, hr, maxh;
		hl = TreeDepth(T->lchild);
		hr = TreeDepth(T->rchild);
		maxh = (hl > hr) ? hl : hr;
		return (maxh + 1);
	}
	else {
		return 0;
	}
}
