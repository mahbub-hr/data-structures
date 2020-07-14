#include<iostream>
#include<cstdio>
#include<fstream>
#include "MinHeap.h"
#define MAX_HEAP_SIZE 100000

#define MAXREAL 999999.0

using namespace std;

int calcNodeHeight(HeapItem  *node) //return height of a node
{
    if(node==0) return -1;
    int l, r;
    l = calcNodeHeight(node->left);
    r = calcNodeHeight(node->right);
    if(l>r) return l+1;
    else return r+1;
}

void printInOrder(HeapItem  *node, int height)
{
    if(node==0) return ;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print item
    for(int i=0;i<height;i++)printf("   ");
	if (node->isLeaf ==1 ) printf("%c\n",node->data);
    else  printf("%03d\n",node->data);

    //print right sub-tree
    printInOrder(node->right, height-1);
}

void generateCode( HeapItem *node, char *code, int &len, ofstream &fout )
{
	if( node->left->isLeaf ==1 )
	{
		code[len] = '0';
		code[len+1] = '\0';
		printf("%c:-> %s   %d\n",node->left->data,code,len+1);
		fout << node->left->data << ": "<<code<<" "<<len+1 <<" ";
	}
	else
	{
		code[len++] = '0';
		generateCode(node->left,code,len,fout);
	}
	
    if( node->right->isLeaf ==1 )
	{
		code[len] = '1';
		code[len+1]= '\0';
		printf("%c:-> %s   %d\n",node->right->data,code,len+1);
		fout << node->right->data << ": "<<code<<" "<<len+1 <<" ";
	}
	else
	{
		code[len++] = '1';
		generateCode(node->right,code,len,fout);	
	}
	
	len--;
	return;
}
void Huffman(char *data, float *key, int n, ofstream &fout)
{
	MinHeap q;
	q.initialize(data,key,n);
	
	for(int i = 1; i < n; i++ )
	{
		HeapItem *z = new HeapItem;
		z->left = q.removeMin();
		z->right = q.removeMin();
		z->key = z->left->key + z->right->key;
		z->data = 0;
		q.insertItem(z);
	}
	
	HeapItem *root = q.removeMin();
	int h = calcNodeHeight(root);
	//cout << h<<endl;
	char *code = new char[h+1];
	int len = 0;
	
	generateCode(root,code,len,fout);
	//printInOrder(root,h);
	//q.printHeap();	
	
	if(code) delete []code;
}

int main()
{
	int n, i = 0, j = 0;
	float  *key ;
	char  *data;
	ofstream fout("code.txt");
	if(!fout) return 0;
//input from file
  // ifstream fin("input.txt");
  
  // if( !fin )
  // {
	  // cout << "File Can't be opened"<<endl;
	  // return 0;
  // }
  
  
  
  // fin >> n;
  // while( i < n )
  // {
	// fin >> ch[i];
	// fin >> key[i++];  
  // }
  

  //input from consol

	cin >> n;
	
	data = new char[n];
	key = new float[n];
	
    for( i = 0; i < n; i++)
	{
		cin >> data[i] >> key[i];
		//cout << data<<" "<< key << endl;
	}
		
	cout << endl << "Gnenerated Code:" << endl;
	Huffman(data,key,n,fout);
	
	if ( data ) delete []data;
	if ( key ) delete []key;
	fout.close();
	
  return 0;
 
}