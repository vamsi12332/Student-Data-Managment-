//#include<stdio.h>
#include"header.h"
static int c1=1;
int main()
{
	sll *headptr=0;
	int c=0;
	char op;
	while(1)
	{
		printf("***************************\n");
		printf("enter the our choice\n");
		printf("a/A)addnewrecord\n d/D)delete a record\n s/S)show the list\n c/C)countnode\n m/M)modify record\n v/V) save records\n t/T)sort the list\n l/L)delete all the list\n r/R) reverse the list\n z/Z)exit the file\n");
		scanf(" %c",&op);
		switch(op)
		{
			case 'a':
			case 'A':
				 addnewrecord(&headptr);break;
			case 'S':
			case 's':
				 showthelist(headptr);break;
			case 'D':
			case 'd':
				deletearecord(&headptr);break;
			case 'V':
			case 'v':
				saverecord(headptr);break;
			case 'C':
			case 'c':
				 c=countnode(headptr);
				 printf("%d\n",c);
				 break;
			case 'L':
			case 'l':
				deleteallnodes(&headptr);break;
			case 'E':
			case 'e':
				reverselist(&headptr);break;
			case 'T':
			case 't':
				sortthelist(headptr);break;
			case 'M':
			case 'm':
				 modifyrecord(&headptr);break;
			case 'R':
			case 'r':
				reverselist(&headptr);break;
			case 'Z':
			case 'z':
				printf("exit the file\n");
				return 0;
			
		}
	}
}
void addnewrecord(sll **ptr)
{
	sll *new;
	new=malloc(sizeof(sll));
	printf("enter the student details\n");
	scanf("%s %f",new->name,&new->percentage);
	new->rollno=c1;
	new->next=*ptr;
	*ptr=new;
}
void showthelist(sll *ptr)
{
	c1=1;
	if(ptr==0)
	{
		printf("there is no records\n");
		return;
	}
	while(ptr)
	{
		ptr->rollno=c1++;
		printf("%d %s %.2f\n",ptr->rollno,ptr->name,ptr->percentage);
		ptr=ptr->next;
	}
}
void deletearecord(sll **ptr)
{
	if(ptr==0)
	{
		printf("there is no records\n");
		return;
	}
	printf("enter your choice\n");
	printf("1)rollno 2)name 3)perecentage\n");
	int op1;
	scanf("%d",&op1);
	sll *del=*ptr,*prev;
	if(op1==1)
	{
		int rollno1;
		printf("enter your roll number\n");
		scanf("%d",&rollno1);
		while(del)
		{ 
			if(del->rollno==rollno1)
			{
				if(*ptr==del)
					*ptr=del->next;
				else
					prev->next=del->next;
				free(del);
				return;
			}
			prev=del;
			del=del->next;
		}			
	}
	else if(op1==2)
	{
		char name1[20];
		printf("enter the name\n");
		scanf("%s",name1);
		while(del)
		{
			if(del->name==name1)
			{
				if(*ptr==del)
					*ptr=del->next;
				else
					prev->next=del->next;
				free(del);
				return;
			}
			prev=del;
			del=del->next;
		}

	}
	else if(op1==3)
	{
		float percentage1;
		printf("enter the precentage\n");
		scanf("%f",&percentage1);
		while(del)
		{
			if(del->percentage==percentage1)
			{
				if(*ptr==del)
					*ptr=del->next;
				else
					prev->next=del->next;
				free(del);
				return;
			}
			prev=del;
			del=del->next;
		}

	}
	printf("suceessfully delete the node\n");
}
void saverecord(sll *ptr)
{
	if(ptr==0)
	{
		printf("No records\n");
		return;
	}
	FILE *fp;
	fp=fopen("student_data.txt","w");
	while(ptr)
	{
		fprintf(fp,"%d %s %.2f\n",ptr->rollno,ptr->name,ptr->percentage);
		ptr=ptr->next;
	}
	printf("data saves.......\n");
	fclose(fp);
}
int countnode(sll *ptr)
{
	int c=0;
	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;

}
void reverselist(sll **ptr)
{
	if(*ptr==0)
	{
		printf("no record\n");
		return;
	}
	int c=countnode(*ptr);
	if(c>1)
	{
		int i;
		sll *temp=*ptr;
		sll **a=malloc(sizeof(sll *)*c);
		for(i=0;i<c;i++)
		{
			a[i]=temp;
			temp=temp->next;
		}
		for(i=c-1;i>0;i--)
		{
			a[i]->next=a[i-1];
			a[0]->next=0;
			*ptr=a[c-1];
		}
	}
	printf("list reversed successfully\n");
}
void deleteallnodes(sll **ptr)
{
	if(*ptr==0)
	{
		printf("there is no records\n");
		return;
	}
	sll *del=*ptr;
	while(del)
	{
		*ptr=del->next;
		free(del);

		del=*ptr;	
	}
	printf("sucessfully delete all nodes\n");
}
void sortthelist(sll *ptr)
{
	if(ptr==0)
	{
		printf("there is no records\n");
		return;
	}
	sll *p1=ptr,t,*p2;
	int i,j,op,c=countnode(ptr);
	printf("options 1) name 2) percentage\n");
	scanf("%d",&op);
	if(op==1)
	{
		for(i=0;i<c-1;i++)
		{
			p2=p1->next;
			for(j=0;j<c-1-i;j++)
			{
				if(strcmp(p1->name,p2->name)>0)
				{
					t.rollno=p1->rollno;
					strcpy(t.name,p1->name);
					t.percentage=p1->percentage;

					p1->rollno=p2->rollno;
					strcpy(p1->name,p2->name);
					p1->percentage=p2->percentage;

					p2->rollno=t.rollno;
					strcpy(p2->name,t.name);
					p2->percentage=t.percentage;
				}
				p2=p2->next;
			}
			p1=p1->next;
		}
	}

	else if(op==2)
	{
		for(i=0;i<c-1;i++)
		{
			p2=p1->next;
			for(j=0;j<c-1-i;j++)
			{
				if(p1->percentage > p2->percentage)
				{
					t.rollno=p1->rollno;
					strcpy(t.name,p1->name);
					t.percentage=p1->percentage;

					p1->rollno=p2->rollno;
					strcpy(p1->name,p2->name);
					p1->percentage=p2->percentage;

					p2->rollno=t.rollno;
					strcpy(p2->name,t.name);
					p2->percentage=t.percentage;
				}
				p2=p2->next;
			}
			p1=p1->next;
		}
	}
	printf("sucessfully sort\n");
}
void modifyrecord(sll **ptr)
{

	if(*ptr==0)
	{
		printf("there is no records\n");
		return;
	}
	sll *temp=*ptr;
	int op;
	printf("enter the options 1)name 2)percentage\n");
	scanf("%d",&op);
	if(op==1)
	{
		char name2[20],name1[20];
		printf("enter the name:\n");
		scanf("%s", name2);
		while(temp)
		{
			if(strcmp(temp->name,name2)==0)
			{
				printf("enter the modify the name\n");
				scanf("%s", name1);
				strcpy(temp->name,name1);

			}
			temp=temp->next;
		}
	}
	else if(op==2)
	{
		int  percentage2,percentage1;
		printf("enter the percentage:\n");   
		scanf("%d",&percentage2);
		while(temp)
		{
			if(temp->percentage==percentage2)
			{
				printf("enter the modify the percentage\n");
				scanf("%d",&percentage1);
				temp->percentage=percentage1;
			}
			temp=temp->next;
		}
	}
	printf("succsessfully modify\n");
}

