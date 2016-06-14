#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node * ref;
struct node{
	int key;
	ref next;
};

ref getNode(int k)
{
	ref p;
	p = (ref)malloc(sizeof(struct node));
	if(p == NULL)
	{
		printf("error");
		exit(0);
	}
	p->key = k;
	p->next = NULL;
	return p;
}

void makeOrderedList(ref head, int k)
{
	ref p1, p2, p;
	p1 = head;
	p2 = head->next;
	while(p2 && p2->key < k)
	{
		p1 = p2;
		p2 = p2->next;
	}
	p = getNode(k);
	p1->next = p;
	p->next = p2;
}

void printList(ref head)
{
	ref p;
	if(head == NULL)
		printf("Empty List!");
	else
		for(p = head; p; p = p->next)
			printf("%4d", p->key);
}

void destroyList(ref &head)
{
	ref p;
	while(head)
	{
		p = head;
		head = head->next;
		free(p);
	}
}

int main()
{
	int n,i;
	ref head;
	srand((unsigned)time(NULL));
	head = (ref)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("error");
		return 0;
	}
	head->next = NULL;

	printf("\nInput number of elements: ");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		makeOrderedList(head, rand() % 100);
	}
	printList(head->next);
	destroyList(head);
	return 0;
}