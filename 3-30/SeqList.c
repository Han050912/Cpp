#define  _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

//¥Ú”°
void Print(SL* sl)
{
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->arr[i]);
	}
	printf("\n");
}

//≥ı ºªØ
void SLInit(SL* sl)
{
	assert(sl);
	sl->arr = NULL;
	sl->capacity = sl->size = 0;
}

//¿©»›
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

//œ˙ªŸ
void Destroy(SL* sl)
{
	if (sl->arr)
	{
		free(sl->arr);
	}
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

// Õ∑≤ÂŒ≤≤Â
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

//Õ∑…æŒ≤…æ
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