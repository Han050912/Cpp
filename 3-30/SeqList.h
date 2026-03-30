#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

////¾²Ì¬Ë³Ðò±í
//#define N 6
//struct SeqList
//{
//	int arr[N];
//	int size;
//};

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//³õÊ¼»¯
void SLInit(SL* sl);

//Ïú»Ù
void Destroy(SL* sl);

//Í·²åÎ²²å
void SLPushBack(SL* sl, SLDataType x);

void SLPushFront(SL* sl, SLDataType x);

//Í·É¾Î²É¾
void SLPopBack(SL* sl);

void SLPopFront(SL* sl);

//´òÓ¡
void Print(SL* sl);

//À©ÈÝ
void Expansion(SL* sl);