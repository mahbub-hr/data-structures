#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3

class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		//allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; //free the memory allocated before
		data = tempData ; //make list to point to new memory
	}

	data[front] = item ; //store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; //deallocate memory
    data = 0; //set to NULL
}

//****************Queue class ends here************************

//****************Dynamic ArrayList class based************************
class ArrayList
{
	int * list;
	int length ;
	int listMaxSize ;
	int listInitSize ;
public:
	ArrayList() ;
	~ArrayList() ;
	int searchItem(int item) ;
    void insertItem(int item) ;
	void removeItem(int item) ;
	void removeItemAt(int item);
	int getItem(int position) ;
	int getLength();
	bool empty();
	void printList();
} ;


ArrayList::ArrayList()
{
	listInitSize = 2 ;
	listMaxSize = listInitSize ;
	list = new int[listMaxSize] ;
	length = 0 ;
}

void ArrayList::insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = new int[listMaxSize] ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        delete[] list ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};

	list[length] = newitem ; //store new item
	length++ ;
}

int ArrayList::searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

void ArrayList::removeItemAt(int position) //do not preserve order of items
{
	if ( position < 0 || position >= length ) return ; //nothing to remove
	list[position] = list[length-1] ;
	length-- ;
}


void ArrayList::removeItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return ; //nothing to remove
	removeItemAt(position) ;
}


int ArrayList::getItem(int position)
{
	if(position < 0 || position >= length) return NULL_VALUE ;
	return list[position] ;
}

int ArrayList::getLength()
{
	return length ;
}

bool ArrayList::empty()
{
    if(length==0)return true;
    else return false;
}

void ArrayList::printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

ArrayList::~ArrayList()
{
    if(list) delete [] list;
    list = 0 ;
}

//******************ArrayList class ends here*************************

//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	ArrayList  * adjList ;
	//define other variables required for bfs such as color, parent, and dist
	//you must use pointers and dynamic allocation
	char *color;
	int *parent;
	int *dist;
	int *start;
	int *finish;
    int time;

public:
	Graph(bool dir = false);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v);
	void removeEdge(int u, int v);
	bool isEdge(int u, int v);
    int getDegree(int u);
    bool hasCommonAdjacent(int u, int v);
    int getDist(int u, int v);
    void printGraph();
	void bfs(int source); //will run bfs in the graph
	void dfs(); //will run dfs in the graph
	void DFSVisit(int u);
	void printParent();
	void printDist();
	void printStartAndFinish();
};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	adjList = 0 ;
	directed = dir ; //set direction of the graph
	//define other variables to be initialized
	color = 0;
	dist = 0;
	parent = 0;
	start = 0;
	finish = 0;
	time = 0;
}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;
	if(adjList!=0) delete[] adjList ; //delete previous list
	adjList = new ArrayList[nVertices] ;

	if(color != 0) delete[]color;
	if(dist != 0) delete []dist;
	if(parent != 0) delete []parent;
	if(start != 0) delete []start;
	if(finish != 0) delete []finish;

	color = new char[n];
	parent = new int[n];
	dist = new int[n];
	start = new int[n];
	finish = new int[n];
}

void Graph::addEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    this->nEdges++ ;
	adjList[u].insertItem(v) ;
	if(!directed) adjList[v].insertItem(u) ;
}

void Graph::removeEdge(int u, int v)
{
    //write this function

    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    this->nEdges-- ;
	adjList[u].removeItem(v) ;
	if(!directed) adjList[v].removeItem(u) ;
}

bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return false; //vertex out of range
    if(adjList[u].searchItem(v) != NULL_VALUE) return true;
    else return false;
}

int Graph::getDegree(int u)
{
    //returns the degree of vertex u
    if(u<0 || u>=nVertices) return NULL_VALUE;
    return adjList[u].getLength();
}

bool Graph::hasCommonAdjacent(int u, int v)
{
    //returns true if vertices u and v have common adjacent vertices
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return false;

    for (int i =0 ; i< adjList[u].getLength(); i++)
    {
         if (adjList[v].searchItem(adjList[u].getItem(i)) != NULL_VALUE) return true;
    }
    return false;
}

void Graph::bfs(int source)
{
    if(source<0 || source>=nVertices) return ;
    //complete this function
    //initialize BFS variables
    for(int i=0; i<nVertices; i++)
    {
        color[i] = 'W' ;
        parent[i] = -1 ;
        dist[i] = INFINITY ;
    }
    Queue q ;
    color[source] = 'G';
    dist[source] = 0 ;
    q.enqueue(source) ;
    int v = 0;

    while( !q.empty() )
    {
        //complete this part
       int u = q.dequeue();

        for (int i =0; i < adjList[u].getLength(); i++)
        {
            v = adjList[u].getItem(i);
            if ( color[v] == 'W')
            {
                parent[v] = u;
                dist[v] = dist[u] + 1;
                color[v] = 'G';
                q.enqueue(v);
            }
        }

        color[u] = 'B' ;
    }
}

void Graph::dfs()
{
    //write this function
    for(int i=0; i<nVertices; i++)
    {
        color[i] = 'W' ;
        parent[i] = -1 ;
        start[i] = 0;
        finish[i] =0;
    }

    time = 0;
    for (int i =0 ; i< nVertices ; i++)
    {
        if (color[i] == 'W')
            DFSVisit(i);
    }

}

void Graph::DFSVisit(int u)
{
    time++;
    start[u] = time;
    color[u] = 'G';

    for(int i = 0; i < adjList[u].getLength(); i++)
    {
        if( color[adjList[u].getItem(i)] == 'W')
        {
            parent[adjList[u].getItem(i)] = u;
            DFSVisit(adjList[u].getItem(i));
        }
    }
    time++;
    finish[u] = time;
    color[u] = 'B';
}

int Graph::getDist(int u, int v)
{
    //returns the shortest path distance from u to v
    //must call bfs using u as the source vertex, then use distance array to find the distance
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return INFINITY ;
    bfs(u);
    return dist[v];
}

void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<adjList[i].getLength();j++)
        {
            printf(" %d", adjList[i].getItem(j));
        }
        printf("\n");
    }
}

void Graph::printParent()
{
    for (int i = 0; i < nVertices; i++)
        printf("%d->%d, ",i,parent[i]);
    printf("\n");
}

void Graph::printDist()
{
    for (int i = 0; i < nVertices; i++)
        printf("%d ",dist[i]);
    printf("\n");
}

void Graph::printStartAndFinish()
{
    for (int i = 0; i < nVertices; i++)
        printf("%d:(%d,%d),",i,start[i],finish[i]);
    printf("\n");
}

Graph::~Graph()
{
    //write your destructor here
    if(parent)  delete []parent;
    if(color)  delete []color;
    if(dist)  delete []dist;
	if(start) delete []start;
	if(finish) delete []finish;
	if(adjList) delete []adjList;
}


//**********************Graph class ends here******************************


//******main function to test your code*************************
int main(void)
{
    int n;
    Graph g;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    g.setnVertices(n);

    while(1)
    {
        printf("1. Add edge. 2. Remove edge 3. Get degree\n");
        printf("4. Has Common Edge. 5. Print Graph 6. BFS\n");
        printf("7. DFS 8. Get Dist 9. Parent\n");
        printf("10.Start Time & Finish Time  0. Exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.addEdge(u, v);
        }
        else if(ch==2)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.removeEdge(u, v);
        }
        else if(ch==3)
        {
            int degree;
            scanf("%d",&degree);
            printf("Degree of %d = %d\n",degree,g.getDegree(degree));
        }
        else if (ch == 4)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%s\n",g.hasCommonAdjacent(u,v) ? "true" : "false");
        }
        else if(ch==5)
        {
            g.printGraph();
        }
        else if(ch==6)
        {
            int s;
            scanf("%d",&s);
            g.bfs(s);
            printf("---------------------------------------------------\n");
            printf("Dist: ");
            g.printDist();
            printf("Parent: ");
            g.printParent();
            printf("---------------------------------------------------\n");
        }
        else if(ch==7)
        {
            g.dfs();
            printf("---------------------------------------------------\n");
            printf("Parent: ");
            g.printParent();
            printf("(Start,Finish): ");
            g.printStartAndFinish();
            printf("---------------------------------------------------\n");
        }
        else if(ch==8)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            printf("---------------------------------------------------\n");
            printf("Distance between %d and %d = %d\n",u,v,g.getDist(u,v));
            printf("---------------------------------------------------\n");
        }
//        else if(ch==9)
//        {
//            g.printParent();
//        }
//        else if(ch==10)
//        {
//           g.printStartAndFinish();
//        }
        else
        {
            break;
        }
    }

}
