#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Contact.h"

////静态顺序表
//#define N 6
//struct SeqList
//{
//	int arr[N];
//	int size;
//};

typedef struct PersonInfo SLDataType;
//typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//初始化
void SLInit(SL* sl);

//销毁
void Destroy(SL* sl);

//头插尾插
void SLPushBack(SL* sl, SLDataType x);

void SLPushFront(SL* sl, SLDataType x);

//头删尾删
void SLPopBack(SL* sl);

void SLPopFront(SL* sl);

//打印
void Print(SL* sl);

//扩容
void Expansion(SL* sl);

//指定位置插入数据
void SLInsert(SL* sl, int pos, SLDataType x);

//指定位置删除数据
void SLDel(SL* sl, int pos);

//查找数据
void SLFind(SL* sl, SLDataType x);