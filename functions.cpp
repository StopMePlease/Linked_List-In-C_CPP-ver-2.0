#include <stdio.h>
#include <stdlib.h>

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

void addFirst(ref &head, ref &tail, int k)
{
	ref p = getNode(k);
	if(head == NULL)
		head = tail = p;
	else
	{
		p->next = head;
		head = p;
	}
}

void addLast(ref &head, ref &tail, int k)
{
	ref p = getNode(k);
	if(head == NULL)
	{
		head = tail = p;
	}
	else
	{
		tail->next = p;
		tail = p;
	}
}

void addLast_2(ref &head, int k)
{
	ref p;
	if(head == NULL)
		head = getNode(k);
	else
	{
		p = head;
		while(p->next)
			p = p->next;
		p->next = getNode(k);
	}
}

void InsertAfter(ref q, int k)
{
	ref p;
	p = getNode(k);
	p->next = q->next;
	q->next = p;
}

void InsertBefore(ref head, ref q,int k)
{
	ref p, r;
	p = getNode(k);
	for(r = head; r->next != q; r = r->next);
	p->next = q;
	r->next = p;
}

void InsertBefore_2(ref q, int k)
{
	ref p;
	p = (ref)malloc(sizeof(struct node));
	if(p == NULL)
	{
		printf("error");
		exit(0);
	}
	*p = *q;
	q->next = p;
	q->key = k;
}

void delBeg(ref &head, ref &tail)
{
	ref q;
	if(head == tail)
	{
		free(head);
		head = tail = NULL;
	}
	else
	{
		q = head;
		head = head->next;
		free(q);
	}
}

void delEnd(ref &head, ref &tail)
{
	ref q;
	if(head == tail)
	{
		free(head);
		head = tail = NULL;
	}
	else
	{
		for(q = head; q->next != tail; q = q->next);
		free(tail);
		tail = q;
		q->next = NULL;
	}
}

void delMid(ref head, ref q)
{
	ref r;
	for(r = head; r->next != q; r = r->next);
	r->next = q->next;
	free(q);
}

void delMid_2(ref q)
{
	ref r;
	r = q->next;
	*q = *r;
	free(r);
}

int length(ref head)
{
	ref p;
	int count = 0;
	for(p = head; p; p = p->next)
		count++;
	return count;
}

void insertAt(ref &head, ref &tail, int pos, int k)
{
	int n, i;
	ref q;
	n = length(head);
	if(pos < 0 || pos > n)
	{
		printf("error");
		return;
	}
	if(pos == 0)
		addFirst(head, tail, k);
	else
		if(pos == n)
			addLast(head, tail, k);
		else
		{
			for(i = 0, q = head; i < pos; i++, q = q->next);
			InsertBefore_2(q, k);
			if(tail->next)
				tail = tail->next;
		}
}

void deleteAt(ref &head, ref &tail, int pos)
{
	int n,i;
	ref q;
	n = length(head);
	if(pos < 0 || pos > n)
	{
		printf("error");
		return;
	}
	if(pos == 0)
		delBeg(head, tail);
	else
		if(pos == n - 1)
			delEnd(head, tail);
		else
		{
			for(i = 0, q = head; i < pos; i++, q = q->next);
			if(q->next == tail)
				tail = q;
			delMid_2(q);
		}
}

void printList(ref head)
{
	ref p;
	if(head == NULL)
		printf("Empty List!");
	else
		for(p = head; p; p=p->next)
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
	int k;
	ref head = NULL, tail = NULL;

	destroyList(head);
	return 0;
}