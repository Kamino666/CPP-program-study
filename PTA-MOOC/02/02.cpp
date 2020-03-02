#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;
List Merge(List L1, List L2);

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2)
{
	List L = (List)malloc(sizeof(struct Node));
	List head = L;
	List tmp1 = L1->Next, tmp2 = L2->Next;
	while (tmp1 && tmp2)  //  当两者都不是NULL时
	{
		if (tmp1->Data < tmp2->Data)
		{
			L->Next = tmp1;
			tmp1 = tmp1->Next;
		}
		else
		{
			L->Next = tmp2;
			tmp2 = tmp2->Next;
		}
		L = L->Next;
	}
	if (tmp1)
		L->Next = tmp1;
	if (tmp2)
		L->Next = tmp2;
	L1->Next = NULL;
	L2->Next = NULL;

	return head;
}