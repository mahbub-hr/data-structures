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

void initializeList()
{
    list = 0;  //initially set to NULL
}

int insertItem(int item) //insert at the beginning of the linked list
{
    struct listNode * newNode ;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
	if(list ==0 ){
     newNode->next = list ; //point to previous first node
     list = newNode ; //set list to point to newnode as this is now the first node
	}
	else if(newNode->item < list)
    return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
    struct listNode *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) break ;
        prev = temp;
        temp = temp->next ; //move to next node
    }
    if (temp == 0) return NULL_VALUE ; //item not found to delete
    if (temp == list) //delete the first node
    {
        list = list->next ;
        free(temp) ;
    }
    else
    {
        prev->next = temp->next ;
        free(temp);
    }
    return SUCCESS_VALUE ;
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
	if(list != 0){
		struct listNode * temp;
		temp = list;
		while(temp!=0)
		{
			printf("%d->", temp->item);
			temp = temp->next;
		}
		printf("\n");
	}
}

int insertLast(int item)  //write your codes here
{
    struct listNode * temp, * newNode ;
    temp = list ; //start at the beginning

    if(list!=0)
    {
        newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
        newNode->item = item ;

        while (temp->next != 0)
        {
            temp = temp->next ; //move to next node
        }

        temp->next=newNode;
        newNode->next = 0;
    }
    else
    {
        insertItem(item);
    }
    return SUCCESS_VALUE ;
}

int insertBefore(int oldItem, int newItem)
{
    //write your codes here
    struct listNode * temp,*prev =0, *newNode ;
	temp = list ; //start at the beginning
	
	while (temp != 0)
	{
		if (temp->item == oldItem)  break;
		prev = temp;	
		temp = temp->next ; //move to next node
	}

	if(temp == 0 || temp==list)  insertItem(newItem);
    else{
		newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
		newNode->item = newItem ;
		newNode->next=temp;
		prev->next=newNode;
	}
    return SUCCESS_VALUE;
}

int deleteAfter(int item)
{
    //write your codes here
    struct listNode * temp,*tempNext ;
    temp = list ; //start at the beginning
	
	if(temp == 0)  return NULL_VALUE;
    while (temp->next != 0)
    {
        if (temp->item == item)
        {
            tempNext=temp->next;
            temp->next=tempNext->next;
            free(tempNext);
            break ;
        }
        temp = temp->next ; //move to next node
    }

    if(temp->next==0) return NULL_VALUE;
    else return SUCCESS_VALUE;
}

int deleteLast()
{
    //write your codes here
    struct listNode * temp,*prev=0 ;
    temp = list ; //start at the beginning
	if(temp == 0) return NULL_VALUE;
	while (temp->next != 0)
	{
		prev = temp;
	    temp = temp->next ; //move to next node
	}
	
	if(temp == list) list=0;
		free(temp);
	if(prev != 0)
	    prev->next=0;
 
    return SUCCESS_VALUE;
}



int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. insert Last. 3. insert Before.\n");
        printf("4. Search item.     5. Delete Item. 6. Delete After.\n");
		printf("7. Delete Last.     8.Print  	    0. Exit\n");

        int ch;
        printf("Enter option: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
		if(ch==2)
		{
		   int item;
		   scanf("%d",&item);
		   insertLast(item);
		}
		else if(ch==3){
		   int oldItem,newItem;
		   scanf("%d%d",&oldItem,&newItem);
		   insertBefore(oldItem,newItem);
		}
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
		else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
		else if(ch==6){
		   int item;
		   scanf("%d",&item);
		   deleteAfter(item);
		}
		else if(ch==7)
		{
           deleteLast();
		}
        else if(ch==8)
        {
            printList();
        }
        else if(ch==0)
        {
            break;
        }
    }

}
