#include "SeqList.h"

int main()
{
	SL s;

	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	Print(&s);

	SLPushFront(&s, 5);
	Print(&s);
	SLPushFront(&s, 6);
	Print(&s);

	SLPopBack(&s);
	Print(&s);

	SLPopFront(&s);
	Print(&s);

	Destroy(&s);

	return 0;
}