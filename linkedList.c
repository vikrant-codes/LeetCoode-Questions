#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data ;
	struct Node *next ;
}	Node ;

struct Node* createNode(int data)
{
	struct Node *new = (struct Node *) malloc( sizeof( struct Node ) ) ;
	new->data = data ;
	new->next = NULL ;
	return new ; 
}

struct Node* build(int *arr, int size)
{
	if( arr!=NULL && size > 0 )		// check point for valid arguments
	{
		struct Node *head = NULL, *last = NULL, *new = NULL ;
		int arrayIndex = 0 ;
		head = createNode( arr[ arrayIndex++ ] ) ;
		last = head ;
		size = size - 1 ;
		
		while( size > 0 && head!= NULL)
		{
			new = createNode( arr[ arrayIndex++ ] ) ;
			last->next = new ;
			last = new ;
			size = size - 1 ;
		}
		return head ;
	}
	else 					// when either pointer to array is null or size is not greater than 0
	{
		printf("\nERROR : Build LinkkedList Filed\n") ;
		return NULL ;
	}
}
void delete(struct Node **head,int data)
{
	while(*head!=NULL)
	{
		if((*head)->data==data)
		{
			*head = (*head)->next ;
			break;
		}
		head = &((*head)->next) ;
	}
	return;
}

void traverse(struct Node *head)
{
	while ( head!=NULL )
	{
		printf("%d\t",head->data) ;
		head = head->next ;
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8 } ;
	int size = sizeof( arr ) / sizeof( arr[0] ) ;
	struct Node *head = build(arr,size) ;
	delete(&head,5) ;
	traverse(head) ;
	
}

