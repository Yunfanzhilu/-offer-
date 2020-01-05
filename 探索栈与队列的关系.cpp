# 探索栈与队列的关系（以《用两个栈组成队列》为例）

## 题目

编写一个类，用两个栈实现队列，支持队列（先进先出）的基本操作:

push:将一个元素置入queue中

​     pop:

- 移除queue中的第一元素

- 此函数无返回值，想处理被移除的元素，必须先调用front()

- 调用者保证queue非空

 front:

- 返回第一个被置入的元素，即返回queue最前端的元素

- 调用者保证queue不空

 back:

- 返回最后一个被插入的元素

- 调用者保证queue非空

## 他人代码（自己稍加改动）
#include "stdafx.h"
#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
class MyTwoStackToQueue
{
public:
	void push(int newnum);
	void pop();
	int front();
	int back();
	int backnum;

private:
	stack<int>pushstack;
	stack<int>popstack;
	void adjust();

};
void MyTwoStackToQueue::adjust()//这个函数时有必要的，它能把第一个栈中所有数集体压缩进第二个栈上
{
	while (!pushstack.empty())
	{
		popstack.push(pushstack.top());
		pushstack.pop();
	}
}

void MyTwoStackToQueue::push(int newnum)//这个函数中我们可以不用想数怎么从一个栈再到另一个栈，直接先把所有的数先压入一个栈中，后面再集体压入下一个栈上
{
		backnum = newnum;
		pushstack.push(newnum);
		
}
void MyTwoStackToQueue::pop()
{
	if (popstack.empty())
		adjust();
	if (popstack.empty())
	{
		cout << "The queue is empty! Can't pop!" << endl;
		return;
	}
	popstack.pop();
}

int MyTwoStackToQueue::front()
{
	if (popstack.empty())
	{
		adjust();
	}
	return popstack.top();
}
int MyTwoStackToQueue::back()
{
	return backnum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i, j;
	int aa = 93;
	MyTwoStackToQueue queue1;
	for (i = 0; i < 10; i++)
	{
		queue1.push(i);
	}
	cout << "front:" << queue1.front() << "," << "back:" << queue1.back() << endl;
	queue1.pop();
	cout << "pop!" << endl;
	cout << "front:" << queue1.front() << "," << "back:" << queue1.back() << endl;
	queue1.push(10);
	cout << "push10!" << endl;
	cout << "front:" << queue1.front() << "," << "back:" << queue1.back() << endl;
	for (j = 0; j < 9; j++)
	{
		queue1.pop();
	}
	cout << "pop*8" << endl;
	cout << "front:" << queue1.front() << "," << "back:" << queue1.back() << endl;
	cout << endl;
	
	return 0;
}


//以下我自己想的代码，可能还有些错误，后面改正再看
#include "stdafx.h"
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class MyTwoStackToQueue
{
public:
	void push(int newnum);
	void pop();
	void adjust();
	int front();
	int back();
private:
	int tempnum;
	stack<int>pushstack;
	stack<int>popstack;
};
void MyTwoStackToQueue::adjust()
{
	while (!pushstack.empty())
	{
		popstack.push(pushstack.top());
		pushstack.pop();
	}
}
void MyTwoStackToQueue::push(int newnum)
{
	
	tempnum = newnum;
	pushstack.push(newnum);

}
void MyTwoStackToQueue::pop()
{
	
	popstack.pop();
}
int MyTwoStackToQueue::front()
{
	if ((!pushstack.empty())&&(popstack.empty()))
	{
		adjust();
	}
	return popstack.top();

}
int MyTwoStackToQueue::back()
{
	if (popstack.empty())
	{
		adjust();
	}
	else
	{
		if (!pushstack.empty())
		{
			return pushstack.top();
		}
		else
		{
			return tempnum;
		}
	}

}
int main()
{
	int i, j;
	int a1 = 92;
	int a2 = 92;
	MyTwoStackToQueue newqueue;
	cout << "循环添加元素的操作：" << endl;
	for (i = 0; i < 10; i++)
	{
		newqueue.push(i);

	}
	cout << newqueue.front() << "应:0," << endl;
	cout<<newqueue.back() << "应:9," << endl;
	cout << "添加单个元素10的操作：" << endl;
	newqueue.push(10);
	cout << newqueue.front() << "应:0," << endl;
	cout<< newqueue.back() << "应:10" << endl;
	newqueue.push(11);
	cout << newqueue.front() << "应:0," << endl;
	cout << newqueue.back() << "应:11" << endl;
	newqueue.push(12);
	cout << newqueue.front() << "应:0," << endl;
	cout << newqueue.back() << "应:12" << endl;
	cout << "删除单个元素的操作：" << endl;
newqueue.pop();
cout << newqueue.front() << "应:1," << endl;
cout<<newqueue.back() << "应:12" << endl;

}
