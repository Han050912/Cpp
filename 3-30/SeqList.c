#define  _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

////打印
//void Print(SL* sl)
//{
//	for (int i = 0; i < sl->size; i++)
//	{
//		printf("%d ", sl->arr[i]);
//	}
//	printf("\n");
//}

//初始化
void SLInit(SL* sl)
{
	assert(sl);
	sl->arr = NULL;
	sl->capacity = sl->size = 0;
}

//扩容
void Expansion(SL* sl)
{
	if (sl->capacity == sl->size)
	{
		int newcapacity = sl->capacity == 0 ? 4 : sl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(sl->arr, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(1);
		}
		sl->arr = tmp;
		sl->capacity = newcapacity;
	}
}

//销毁
void Destroy(SL* sl)
{
	if (sl->arr)
	{
		free(sl->arr);
	}
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

// 头插尾插
void SLPushBack(SL* sl, SLDataType x)
{
	assert(sl);
	Expansion(sl);
	
	sl->arr[sl->size++] = x;
}

void SLPushFront(SL* sl, SLDataType x)
{
	assert(sl);
	Expansion(sl);

	for (int i = sl->size; i > 0; --i)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[0] = x;
	++sl->size;
}

//头删尾删
void SLPopBack(SL* sl)
{
	assert(sl);
	assert(sl->size);

	--sl->size;
}

void SLPopFront(SL* sl)
{
	assert(sl);
	assert(sl->size);

	for (int i = 0; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	--sl->size;
}

//指定位置之前插入数据
void SLInsert(SL* sl, int pos, SLDataType x)
{
	assert(sl);
	assert(pos >= 0 && pos <= sl->size);

	Expansion(sl);
	for (int i = sl->size - 1; i >= pos; --i)
	{
		sl->arr[i + 1] = sl->arr[i];
	}
	sl->arr[pos] = x;
	++sl->size;
}

//指定位置之前删除数据
void SLDel(SL* sl, int pos)
{
	assert(sl);
	assert(pos > 0 && pos <= sl->size);

	for (int i = pos; i < sl->size; i++)
	{
		sl->arr[i - 1] = sl->arr[i];
	}
	--sl->size;
}

////查找数据
//void SLFind(SL* sl, SLDataType x)
//{
//	assert(sl);
//
//	for (int i = 0; i < sl->size; i++)
//	{
//		if (sl->arr[i] == x)
//		{
//			printf("找到了，下标为：%d", i);
//			return;
//		}
//	}
//	printf("没找到\n");
//}