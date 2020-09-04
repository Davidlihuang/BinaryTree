#include "binarytree.h"

using namespace std;
//������
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
//������
void DestroyTree(Bitree& T);

//�ݹ������
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
//�ǵݹ������
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

//�������
void LayerTraverseNoRecurse(Bitree T)
{
	//1�����ڵ���� 2�����ڵ���ӣ������亢�ӽ�����  3�����Ӳ�������Ԫ�غ������
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

