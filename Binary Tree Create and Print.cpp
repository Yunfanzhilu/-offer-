// Binary Tree Create and Print.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

//����ڵ�
typedef struct node
{
	struct node *lchild;
	struct node *rchild;
	int data;
}BiTreeNode;


//����ǰ��˳����������
void createBiTree(BiTreeNode *&T) //&����˼�Ǵ������ڵ�ָ������ã������ڵȼ��� BiTreeNode* &T,Ŀ�����ô��ݽ�����ָ�뷢���ı�
{
	int c;
	cin >> c;
	if (0 == c)             //������#ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�
		T = NULL;

	else
	{
		T = new BiTreeNode;
		T->data = c;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}

//ǰ���������������ӡ
void preTraverse(BiTreeNode* T)
{
	if (T)
	{
		cout << T->data <<" ";
		preTraverse(T->lchild);
		preTraverse(T->rchild);
	}
}
//�����������������ӡ
void midTraverse(BiTreeNode* T)
{
	if (T)
	{
		midTraverse(T->lchild);
		cout << T->data << " ";
		midTraverse(T->rchild);
	}
}
//������������������ӡ
void postTraverse(BiTreeNode* T)
{
	if (T)
	{
		postTraverse(T->lchild);
		postTraverse(T->rchild);
		cout << T->data << " ";
	}
}
//�����ӡ������(������ά�������ʽ)

vector<vector<int>> temp;
vector<vector<int>>deeptree(BiTreeNode* T, int d)
{





	if (T == NULL)
	{
		return temp;
	}
	else if (temp.size() == d)
	{
		temp.push_back(vector<int>());//���Ӹþ�ᷢ��������ʾԽ�磬֮���ص�����
	}



	temp[d].push_back(T->data);

	deeptree(T->lchild, d + 1);
	deeptree(T->rchild, d + 1);


	return temp;
}
//�����ӡ�����������е�˼�룩
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
	BiTreeNode *T;               //����һ��ָ����������ڵ��ָ��               
	createBiTree(T);
	cout << "������������ɣ�" << endl;
	cout << "ǰ�������������" << endl;
	preTraverse(T);
	cout << endl;
	cout << "���������������" << endl;
	midTraverse(T);
	cout << endl;
	cout << "���������������" << endl;
	postTraverse(T);
	cout << endl;
	cout << "�����ӡ����������ά����˼�룩���Է��д�ӡ��" << endl;
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
	cout << "�����ӡ�����������е�˼�룩��" << endl;
	int m, n;
	for (m = 0; m <r1.size(); m++)
	{
		cout <<" "<< r1[m] ;
	}
	cout << endl;
		return 0;
}