#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*header;
typedef struct node NODE;

void creation();
void display();
void insert_beg(int item);
void insert_spec(int item,int KEY);
void delete_spec(int KEY);

int main()
{
	header=(NODE*)malloc(sizeof(NODE));
	header->data=-9999;
	header->link=header;
	int c,k,e,item,KEY;
	creation();
	display();
	do
	{
		printf("\n1.Insertion\n2.Deletion\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:	printf("\nEnter the item to be added:");
				scanf("%d",&item);
				printf("\n1.At beginning\n2.At specified position\n");
				scanf("%d",&k);
				switch(k)
				{
					case 1: insert_beg(item);
						break;
					case 2: printf("\nEnter the key:");
						scanf("%d",&KEY);
						insert_spec(item,KEY);
						break;
					default: printf("\nInvalid Option!!!\n");
				}
				display();
				break;
			case 2:
				printf("\nEnter the element:\n");
				scanf("%d",&KEY);
				delete_spec(KEY);
				display();
				break;
			default: printf("\nInvalid Option!!!\n");
		}
		printf("\n1.Continue..... \n2.Exit....\n");
		scanf("%d",&e);
	}while(e==1);
	return 0;
}
void creation()
{
	NODE *ptr,*cptr;
	int x;
	ptr=(NODE*)malloc(sizeof(NODE));
	printf("\nEnter the first element:");
	scanf("%d",&ptr->data);
	header->link=ptr;
	ptr->link=header;
	do
	{
		cptr=(NODE*)malloc(sizeof(NODE));
		printf("\nEnter the next element:");
		scanf("%d",&cptr->data);
		cptr->link=header;
		ptr->link=cptr;
		ptr=cptr;
		printf("\n1.Continue..... \n2.Exit....\n");
		scanf("%d",&x);	
	}while(x==1);

}
void display()
{
	NODE *p;
	if(header->link==header)
	{
		printf("\nCLL is empty!!\n");
		return;
	}
	p=header->link;
	while(p!=header)
	{
		printf("-> %d ",p->data);
		p=p->link;
	}
}
void insert_beg(int item)
{
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	p->data=item;
	if(header->link==header)
	{
		header->link=p;
		p->link=header;
	}
	else
	{
		
		p->link=header->link;
		header->link=p;
	}
}
void insert_spec(int item,int KEY)
{
	NODE *p,*loc;
	p=(NODE*)malloc(sizeof(NODE));
	p->data=item;
	loc=header->link;
	while(loc->link!=header && loc->data!=KEY)
		loc=loc->link;
	if(loc->link==header)
		printf("\nInvalid Position!!!!\n");
	else
			p->link=loc->link;
	loc->link=p;
}
void delete_spec(int KEY)
{
	NODE *p,*loc;
	if(header->link==header)
	{
		printf("\nNull list\n");
	}
	else
	{
		p=header->link;
		loc=header->link;
		while(p!=NULL && p->data!=KEY)
		{
				loc=p;
				p=p->link;	
		}
		if(p->link==NULL)
			printf("\nInvalid position!!!\n");
		else
		{
			loc->link=p->link;
			free(p);
		}
	}
}










