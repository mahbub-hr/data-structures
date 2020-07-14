#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * list;
struct listNode * tail;

void initializeList()
{
    list = 0;  //initially set to NULL
	tail = 0;
}

struct listNode * searchItem(int item)
{
	struct listNode * temp ;
	temp = list ; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ; //move to next node
	}
	return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

void printList()
{
    struct listNode * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

//add required codes to insert item at the beginning, remember to properly set the tail pointer!
int insertItem(int newItem)
{
	//write your codes here
	struct listNode *newNode = (struct listNode*)malloc(sizeof(struct listNode));
	newNode->item = newItem;
	newNode->next = list;
	list = newNode;
	
	if(tail == 0) {
	   tail = newNode;
	}
	
	return SUCCESS_VALUE;
}

//add required codes to delete item, remember to properly set the tail pointer!
int deleteAfter(int item)
{
	struct listNode * temp,*ItemToDelete ;
	temp = list ; //start at the beginning
	if(temp == 0)  return NULL_VALUE;
	
	while (temp->next != 0)
	{
		if (temp->item == item)
		{
			ItemToDelete = temp->next;
			temp->next=ItemToDelete->next;
			if(ItemToDelete == tail) tail = temp; 
			free(ItemToDelete);
			break ;
		}
		temp = temp->next ; //move to next node
	}

	if(temp == tail) return NULL_VALUE;
	else return SUCCESS_VALUE;
}

int insertLast(int item)
{
    //write your codes here
	
	listNode *newNode;
    if(tail!=0){
		newNode = (struct listNode*) malloc(sizeof(struct listNode));
		newNode->item = item;
		tail->next = newNode;
		tail = newNode;
		tail->next = 0;	
	}
	else 
		insertItem(item);
	
	return SUCCESS_VALUE;
}


int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Insert Last. 3. Search Item.\n");
        printf("4. Delete After.    5. Print.       0. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
		else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            insertLast(item);
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            deleteAfter(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
		
        else if(ch==5)
        {
            printList();
        }
        else if(ch==0)
        {
            break;
        }
    }

}
