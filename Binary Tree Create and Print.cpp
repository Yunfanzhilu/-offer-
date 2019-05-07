// Binary Tree Create and Print.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

//定义节点
typedef struct node
{
	struct node *lchild;
	struct node *rchild;
	int data;
}BiTreeNode;


//按照前序顺序建立二叉树
void createBiTree(BiTreeNode *&T) //&的意思是传进来节点指针的引用，括号内等价于 BiTreeNode* &T,目的是让传递进来的指针发生改变
{
	int c;
	cin >> c;
	if (0 == c)             //当遇到#时，令树的根节点为NULL，从而结束该分支的递归
		T = NULL;

	else
	{
		T = new BiTreeNode;
		T->data = c;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}

//前序遍历二叉树并打印
void preTraverse(BiTreeNode* T)
{
	if (T)
	{
		cout << T->data <<" ";
		preTraverse(T->lchild);
		preTraverse(T->rchild);
	}
}
//中序遍历二叉树并打印
void midTraverse(BiTreeNode* T)
{
	if (T)
	{
		midTraverse(T->lchild);
		cout << T->data << " ";
		midTraverse(T->rchild);
	}
}
//后续遍历二叉树并打印
void postTraverse(BiTreeNode* T)
{
	if (T)
	{
		postTraverse(T->lchild);
		postTraverse(T->rchild);
		cout << T->data << " ";
	}
}
//按层打印二叉树(建立二维数组的形式)

vector<vector<int>> temp;
vector<vector<int>>deeptree(BiTreeNode* T, int d)
{





	if (T == NULL)
	{
		return temp;
	}
	else if (temp.size() == d)
	{
		temp.push_back(vector<int>());//不加该句会发生错误，显示越界，之后重点来看
	}



	temp[d].push_back(T->data);

	deeptree(T->lchild, d + 1);
	deeptree(T->rchild, d + 1);


	return temp;
}
//按层打印二叉树（队列的思想）
vector<int> PrintFromTopToBottom(BiTreeNode* T) {
	queue<BiTreeNode*> q;
	q.push(T);
	vector<int> r;
	while (!q.empty()) {
		T = q.front(); q.pop();
		if (!T) continue;
		r.push_back(T->data);
		q.push(T->lchild);
		q.push(T->rchild);
	}
	return r;

}






/*vector<int> LevelPrint(BiTreeNode* T) {
		
		vector<int> res;

		deeptree(T, 0);
		int n = temp.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < temp[i].size(); j++){

				res.push_back(temp[i][j]);
			}
		return res;
	}

	*/











int main()
{
	int i, j,len;
	
	int d=0;
	vector<vector<int>>res;
	vector<int>r1;
	BiTreeNode *T;               //声明一个指向二叉树根节点的指针               
	createBiTree(T);
	cout << "二叉树创建完成！" << endl;
	cout << "前序遍历二叉树：" << endl;
	preTraverse(T);
	cout << endl;
	cout << "中序遍历二叉树：" << endl;
	midTraverse(T);
	cout << endl;
	cout << "后序遍历二叉树：" << endl;
	postTraverse(T);
	cout << endl;
	cout << "按层打印二叉树（二维数组思想）可以分行打印：" << endl;
	res=deeptree(T,d);
	len = res.size();
	for (i = 0; i <res.size(); i++)
	{

		for (j = 0; j < res[i].size(); j++)
		{
			cout << " "<<res[i][j];
		}
		cout << endl;
		}
	r1 = PrintFromTopToBottom(T);
	cout << "按层打印二叉树（队列的思想）：" << endl;
	int m, n;
	for (m = 0; m <r1.size(); m++)
	{
		cout <<" "<< r1[m] ;
	}
	cout << endl;
		return 0;
}