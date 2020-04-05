#include<stdio.h>
#include<stdlib.h>

typedef struct Node_tag
{
	int data;
	int visited;
	struct Node_tag *left;
	struct Node_tag *right;
	struct Node_tag *next;
}Node;

Node* newNode(int data) 
{ 
     Node* node = (Node*)malloc(sizeof(Node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
     node->next = NULL;
     node->visited=0;
     printf("Node created whose data is %d and visited flag is set to %d \n",node->data,node->visited);
  
     return(node); 
} 

Node* traverse_mark(Node *root)
{
	Node *prev,*curr;
	curr=root;
	prev=NULL;
	curr->visited=1;
	curr->next=prev;
	while(curr!=NULL)
	{
		while(curr->left && curr->left->visited!=1)
		{
			prev=curr;
			curr=curr->left;
			curr->next=prev;
			curr->visited=1;
		}
		if(curr->right==NULL || curr->right->visited==1)
		{
			prev=curr;
			curr=curr->next;
		}
		else
		{
			prev=curr;
			curr=curr->right;
			curr->visited=1;
			curr->next=prev;
		}
	}
	return root;
}

void print_visited(Node* root)
{
	Node *tmp;
	printf("Visited flag of node whose data is %d,is set to %d \n",root->data,root->visited);
	printf("Visited flag of node whose data is %d,is set to %d \n",	root->left->data,root->left->visited);
	printf("Visited flag of node whose data is %d,is set to %d \n",root->right->data,root->right->visited);
	printf("Visited flag of node whose data is %d,is set to %d \n",root->left->left->data,root->left->left->visited);
	printf("Visited flag of node whose data is %d,is set to %d \n",root->left->right->data,root->left->right->visited);
	printf("Visited flag of node whose data is %d,is set to %d \n",root->left->right->left->data,root->left->right->left->visited);
	printf("Visited flag of node whose data is %d,is set to %d \n",root->right->left->data,root->right->left->visited);
	printf("Visited flag of node whose data is %d,is set to %d \n",root->right->right->data,root->right->right->visited);
	printf("Visited flag of node whose data is %d,is set to %d \n",root->right->right->right->data,root->right->right->right->visited);
}

void main()
{
	int a=0;
	Node *root;
	root=newNode(1);
	root->left=newNode(2);
	root->right = newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->left->right->left=newNode(6);
	root->right->left=newNode(7);
	root->right->right=newNode(8);
	root->right->right->right=newNode(9);
	
	root = traverse_mark(root);
    printf("------------------------------------------------------------------------------------------ \n"); 
	print_visited(root);  
}
