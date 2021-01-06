#include<stdio.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node *llink;
  struct node *rlink;  
};
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
 {
  printf("mem full\n");
  exit(0);
 }
 return x;
} 

NODE insert_rear(int item,NODE head)
{
	NODE temp,cur;
	temp=getnode();
	temp->info=item;
	cur=head->llink;
	head->llink=temp;
	temp->rlink=head;
	temp->llink=cur;
	cur->rlink=temp;
	return head;
}

NODE insert_leftpos(int item,NODE head)
{
NODE temp,cur,prev;
if(head->rlink==head)
{
printf("list empty\n");
return head;
}
cur=head->rlink;
while(cur!=head)
{
if(item==cur->info)break;
cur=cur->rlink;
}
if(cur==head)
{
 printf("key not found\n");
 return head;
 }
 prev=cur->llink;
 printf("enter item towards left of %d=",item);
 temp=getnode();
 scanf("%d",&temp->info);
 prev->rlink=temp;
 temp->llink=prev;
 cur->llink=temp;
 temp->rlink=cur;
 return head;
}

NODE delete_position(int pos,NODE head)
{
	NODE p,q;
	int c=0;
	if(head==NULL)
	{
		printf("empty list \n");
		return head;
	}
	p=head;
	while((p->rlink!=NULL)&&(c!=pos))
	{
		q=p;
		p=p->rlink;
		c++;
	}
	if(c==pos)
	{
		printf("deleted item at %d = %d ",pos,p->info);
		q->rlink=p->rlink;
		if(p->rlink!=NULL)
			(p->rlink)->llink=q;
		free(p);
	}
	else
		printf("invalid position \n");
	return head;
}

void display(NODE head)
{
	if(head->rlink==head)
	{
		printf("empty list \n");
	}
	printf("contents of list : \n");
	NODE temp;
	temp=head->rlink;
	while(temp!=head)
	{
		printf("%d\n",temp->info);
		temp=temp->rlink;
	}
}

int main()
{
	NODE head;
int item, choice,pos;
head=getnode();
head->rlink=head;
head->llink=head;
for(;;)
{
printf("\n 1:Insert at rear\n 2:insert to left of key item \n 3:Delete at a position\n 4:display the linked list \n 5:Exit\n");
printf("enter the choice\n");
scanf("%d",&choice);
switch(choice)
 {
  case 1:printf("enter the item \n");
	 scanf("%d",&item);
	 head=insert_rear(item,head);
	 break;
  
  case 2:printf("enter the key item \n");
	 scanf("%d",&item);
	 head=insert_leftpos(item,head);
	 break;
 
  case 3:printf("enter the position\n");
		 scanf("%d",&pos);
		 head=delete_position(pos,head);
		 break;
  case 4:display(head);
	 break;
 default:exit(0);
	
 }
}

}
