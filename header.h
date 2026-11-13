#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct student
{
	int rollno;
	char name[20];
	float percentage;
	struct student *next;
}sll;
void addnewrecord(sll **);
void deletearecord(sll **);
void showthelist(sll *);
void saverecord(sll *);
int countnode(sll *);
void reverselist(sll **);
void deleteallnodes(sll **);
void modifyrecord(sll **);
void sortthelist(sll *);
