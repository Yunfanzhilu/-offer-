// SequenceList.cpp : 定义控制台应用程序的入口点。
//顺序表的创建、元素删除、遍历

#include "stdafx.h"
#include<stdio.h>
#define length 5

int _tmain(int argc, _TCHAR* argv[])
{
	int OrderedArray[length];//初始化空的顺序表
	int i, data;
	printf("请输入数据：");
	for (i = 0; i <length; i++)
	{
		//依次输入数据
		scanf("%d",&data);
		OrderedArray[i] = data;

	}
	for (i = 0; i < length; i++)
	{
		printf("%d", OrderedArray[i]);
		
	}
	printf("\n");
	//删除表中的第四个数据元素
	for (i = 3; i < length; i++)
	{
		OrderedArray[i] = OrderedArray[i + 1];
	}
	for (i = 0; i < length-1; i++)
	{
		printf("%d", OrderedArray[i]);

	}
	printf("\n");
	return 0;
}
