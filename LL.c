#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*start;
typedef struct node NODE;

void creation();
void display();
void insert_beg(int item);
void insert_spec(int item,int KEY);
void delete_beg();
void delete_end();
void delete_spec(int KEY);

int main()
{
	start=NULL;
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
				printf("\n1.At beginning\n2.At end\n3.At specified position\n");
				scanf("%d",&k);
				switch(k)
				{
					case 1: delete_beg();
						break;
					case 2: delete_end();
						break;
					case 3: printf("\nEnter the key:");
						scanf("%d",&KEY);
						delete_spec(KEY);
						break;
					default: printf("\nInvalid Option!!!\n");
				}
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
	if(start==NULL)
		printf("\nEmpty list!!!");
	ptr=(NODE*)malloc(sizeof(NODE));
	printf("\nEnter the first element:");
	scanf("%d",&ptr->data);
	start=ptr;
	do
	{
		cptr=(NODE*)malloc(sizeof(NODE));
		printf("\nEnter the next element:");
		scanf("%d",&cptr->data);
		cptr->link=NULL;
		ptr->link=cptr;
		ptr=cptr;
		printf("\n1.Continue..... \n2.Exit....\n");
		scanf("%d",&x);	
	}while(x==1);

}
void display()
{
	NODE *p;
	p=start;
	while(p!=NULL)
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
	p->link=start;
	start=p;
}
void insert_spec(item,KEY)
{
	NODE *p,*loc;
	p=(NODE*)malloc(sizeof(NODE));
	p->data=item;
	loc=start;
	while(loc->link!=NULL && loc->data!=KEY)
		loc=loc->link;
	if(loc->link==NULL)
		printf("\nInvalid Position!!!!\n");
	else
			p->link=loc->link;
	loc->link=p;
}
void delete_beg()
{
	NODE *p;
	if(start==NULL)
		printf("\nNull list\n");
	else
	{
		p=start;
		printf("\nDeleted element :%d\n",p->data);
		start=p->link;
		free(p);
	}
}
void delete_end()
{
	NODE *p,*loc;
	if(start==NULL)
		printf("\nNull list\n");
	else
	{
		p=start;
		while(p->link!=NULL)
		{
			loc=p;
			p=p->link;
		}
		loc->link=NULL;
		printf("\nDeleted element :%d\n",p->data);
		free(p);
	}
}
void delete_spec(int KEY)
{
	NODE *p,*loc;
	if(start==NULL)
	{
		printf("\nNull list\n");
	}
	else
	{
		p=start;
		while(p!=NULL && p->data!=KEY)
		{
				loc=p;
				p=p->link;	
		}
		if(p->link==NULL)
			printf("\nInvalid position!!!\nOr Its the last element,you have to take the 2 option\n");
		else
		{
			loc->link=p->link;
			free(p);
		}
	}
}
	
			
