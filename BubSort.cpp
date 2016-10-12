#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int  data;
	struct LNode *next;
}LNode,*Linklist;

Linklist create()
{
	Linklist head, p, q;
	int i = 0;
	int x;

	head = (Linklist)malloc(sizeof(LNode));
	q = NULL;
	while (1)
	{
		printf("please input the node:");
		scanf("%d", &x);
		if (x == 0) { break; }
		p = (Linklist)malloc(sizeof(LNode));
		p->data = x;
		if (++i == 1)
		{
			head->next = p;
		}
		else
		{
			q->next = p;
		}
		q = p;
	}
	q->next = NULL;
	return head;
}


Linklist Sort(Linklist L){
	Linklist p, q;
	int temp;
	for (p = L; p != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (p->data>q->data)
			{
				temp = q->data;
				q->data = p->data;
				p->data = temp;
			}
		}
	}
	return L;
}
int main(){
	Linklist L,S, K;
	L = create();
	printf("初始化的单链表数据序列为:\n");
	for (S = L->next; S != NULL; S = S->next)
		printf("%d ", S->data);
	Sort(L);
	printf("\n按递增顺序排序后的序列为:\n");
	for (K = L->next; K != NULL; K = K->next)
		printf("%d==>", K->data);
	getchar();
	return 0;
}