// Code to play with linked lists
#include<stdio.h>
#include<stdlib.h>

typedef struct Node						// structure of the Node specified
{
	int data ;						// data of the structure
	struct Node *next ;					// address of next Node
}	Node ;

struct Node* createNode(int data)
{
	struct Node *new = (struct Node *) malloc( sizeof( struct Node ) ) ;
	if( new==NULL )						
	{
		printf("\nERROR: Memory allocation(malloc) failed...\n");
		exit(0);					// in case malloc fails to allocate the memory
	}
	new->data = data ;
	new->next = NULL ;
	return new ; 						// on success return thee adrres of newly created Node
}

struct Node* build(int *arr, int size)				// creating a linked list from a array
{
	if( arr != NULL && size > 0 )				// check point for valid arguments
	{
		struct Node *head = NULL, *last = NULL, *new = NULL ;
		int arrayIndex = 0 ;				// varable to iterate on array 
		head = createNode( arr[arrayIndex++] ) ;	// create first element and join rest using loop
		last = head ;
		size = size - 1 ;
		
		while( size > 0 && head != NULL)			// join the elements one by one
		{
			new = createNode( arr[arrayIndex++] ) ;
			last->next = new ;
			last = new ;
			size = size - 1 ;			// decrement the size of array  ---really Important---
		}
		return head ;					// on success return head of linked list
	}
	else 							// when either pointer to array is null or size is not greater than 0
	{
		printf("\nERROR : Build LinkkedList Filed Invalid Arguments to build()...\n") ;
		return NULL ;					// on failure return NULL
	}
}
int delete(struct Node **head, int data)
{
	struct Node *temp = NULL ;				// temporary variable to free the pointer which w
	while( *head != NULL )
	{
		if( (*head)->data == data )				// when required elemet is found
		{
			temp = *head ;				// store the pointer temporarily too free it	
			*head = (*head)->next ;			// remove the link
			free(temp) ;				// free the deleted pointer
			return 0;				// on successful deletion return 0
		}
		head = &( (*head)->next ) ;			// iterate on head 
	}
	return -1;						// on failure return -1
}

void traverse(struct Node *head)				// traverse/print the linked list
{
	while ( head != NULL )					// loop till reach to end/NULL
	{
		printf("%d\t", head->data) ;			// print the data of current Node
		head = head->next ;
	}
	printf("\n");
}

int insertAsc(struct Node **head, int data )			// insert the element in linked list keeping it ASC sorted
{
	struct Node *new = createNode( data )  ;		// create the node from data
	while( *head != NULL )					// iterate on linked list
	{
		if( ((*head)->data) >= data )			// find first greater element than given
		{
			new->next = *head ;			// add it before just large elemnt from list
			*head = new ;
			return 0 ;				// on success return 0
		}
		head = &( (*head)->next ) ;
	}
	*head = new ;						// if Nothing is there or all elements are less then just add new Node
	return 0;
}

struct Node* buildSortedAsc(int *arr, int size)			// build sorted(ASC) linked list from given array
{
	if( arr != NULL && size > 0 )				// check point for valid arguments
	{
		struct Node *head = NULL ;			// head of the linked list
		for(int i=0; i<size ; i++)
			insertAsc(&head, arr[i]) ;		// insert elemts one by one keeping it sorted
		return head ;					// return the head of created linked list
	}
	else
	{
		printf("\nERROR : BuildSorted LinkkedList Filed Invalid Arguments to build()...\n") ;
		return NULL ;					// on failure return NULL
	}
}

int* getRandomArray(int size)
{
	int *arr = (int *) malloc( sizeof(int) * size ) ;
	for(int i=0; i<size ; i++)
		arr[i] = rand() % size ;
	return arr ;
}
int main(int argc,char **argv)
{
	int size = 10 ;						// set the size of input
	int *arr = getRandomArray(size);			// generate the random array of given size
	struct Node *head = buildSortedAsc(arr, size) ;		// build ascending linked list from array
	traverse(head) ;					// traverse linked list
}

