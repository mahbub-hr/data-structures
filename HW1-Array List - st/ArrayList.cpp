#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

int listMaxSize;
int * list;
int length;


void initializeList()
{
    listMaxSize = LIST_INIT_SIZE;
    list = (int*)malloc(sizeof(int)*listMaxSize) ;
    length = 0 ;
}

int searchItem(int item)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        if( list[i] == item ) return i;
    }
    return NULL_VALUE;
}

int insertItem(int newitem)
{
    int * tempList ;
    if(listMaxSize == 0)
    {
        initializeList();
    }
    else if (length == listMaxSize)
    {
        //allocate new memory space for tempList
        listMaxSize = 2 * listMaxSize ;
        tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
        int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
    }

    list[length] = newitem ; //store new item
    length++ ;
    return SUCCESS_VALUE ;
}

int shrink()
{
    int i, *tempList;
    if( length == listMaxSize/2 && listMaxSize > LIST_INIT_SIZE)
    {
        listMaxSize = listMaxSize/2;
        tempList = (int *) malloc(sizeof(int) * listMaxSize);

        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory

        return SUCCESS_VALUE;
    }
    else return NULL_VALUE;
}

int deleteItemAt(int position) //version 2, do not preserve order of items
{
    if ( position >= length ) return NULL_VALUE;
    list[position] = list[length-1] ;
    length-- ;
    shrink();
    return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
    int position;
    position = searchItem(item) ;
    if ( position == NULL_VALUE ) return NULL_VALUE;
    deleteItemAt(position) ;
    shrink();
    return SUCCESS_VALUE ;
}

int deleteLast()//my code
{
    if(length>=0)
    {
        int temp;
        length--;
        temp = list[length];
        shrink();
    }
    return temp;
}

int deleteAll()//my code
{
    length =0;

    if(listMaxSize > LIST_INIT_SIZE)
    {
        free(list);
        initializeList();
    }

    return SUCCESS_VALUE;
}

int clear()//my code
{
    length = 0;
    listMaxSize =0;
    free (list);
    return SUCCESS_VALUE;
}

void printList()
{
    int i;
    for(i=0; i<length; i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

int getLength()//my code
{
    return length;
}

int insertItemAt(int pos, int item)//my code
{
    int temp;

    if(pos<length)
    {
        insertItem(item);
        temp = list[pos];
        list[pos] = list[length-1];
        list[length-1] = temp;

        return SUCCESS_VALUE;
    }
    else return NULL_VALUE;
}

int main()
{
    int i=0,temp1,temp2,result;
    char ch[80];
    initializeList();
    scanf("%s",ch);
    while(ch[i] !='\0')
    {
        if(ch[i]>='0' && ch[i] <='9')
        {
            temp1=ch[i] - '0';
            insertItem(temp1);
            i++;
            //printf("%d",temp1);
        }
        else
        {

            temp1 = deleteLast();
            temp2 = deleteLast();

            if((ch[i] == '+'))
                result= temp2 + temp1;
            insertItem(result);
            i++;
            //printf("%d",result);

            else if(ch[i]=='-')
            {
                result=temp2-temp1;
                insertItem(result);
                i++;
                //printf("%d",result);
            }
            else if(ch[i] == '*')
            {
                result=temp2*temp1;
                insertItem(result);
                i++;
                //printf("%d",result);
            }
            else
            {
                result=temp2/temp1;
                insertItem(result);
                i++;
                //printf("%d",result);
            }
        }
    }

    printf("Result = %d",deleteLast());

}

/*int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. insertItemAt. 3. Delete item.\n");
        printf("4. Delete item at. 5. DeleteLast 6. DeleteAll 7.Clear\n");
        printf("8.Print. 9. exit. \n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==4)
        {
            int pos;
            scanf("%d", &pos);
            deleteItemAt(pos);
        }
		else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
		else if(ch==2)
		{
			int pos,item;
			scanf("%d%d",&pos,&item);
			insertItemAt(pos,item);
		}
        else if(ch==5)
        {
			printf("%d deleted",deleteLast());
        }
        else if(ch==6)
        {
            deleteAll();
        }
		else if(ch==7)
			clear();
		else if(ch==8)
			printList();
		else break;
    }

}*/
