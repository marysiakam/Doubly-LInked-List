#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Node {
	struct Node* next;
	struct Node* prev;
	int data;
}Node;

struct Node* create_dll_from_array(int array[], int);
struct Node* createNode(int);
void print_dll(struct Node*);
void insert_after(struct Node*, int, int);
void delete_element(struct Node*, int); 
void sort_dll(struct Node*);
void freeList(struct Node*);

struct Node* create_dll_from_array(int  array[],int size){	
	struct Node* head = NULL;
	int i;
	for(i=size-1; i>=0; i--){
		struct Node* temp = createNode(array[i]);
		
		if (head == NULL){
			head =temp; 
		}
		else {
			head->prev= temp;
			temp->next= head;
			head = temp;
		}

	}
	return head;
} 

struct Node* createNode(int value){
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	if(temp == NULL) return NULL;

	temp->data= value;
	temp->next= NULL;
	temp->prev= NULL;

	return temp;

}
void print_dll(struct Node* head){
	struct Node* ptr= head;
	while(ptr != NULL){
		printf("%d  ",ptr->data);
		ptr= ptr->next;
	}
	printf("\n");
}


void insert_after(Node* head, int valueToInsertAfter, int valueToBeInserted){
	struct Node* newNode = createNode(valueToBeInserted);
	struct Node* temp = head;
	struct Node* lastNode;
	
	while(temp != NULL){
		if(temp->data == valueToInsertAfter){
			temp->next->prev= newNode;
			newNode->next =temp->next;
			newNode->prev =temp;
			temp->next = newNode;
			return;
		}
		if(temp->next ==NULL){
			lastNode = temp;
		}
		temp= temp->next;

	}

	lastNode->next = createNode(valueToBeInserted);
	lastNode->next->prev = lastNode;

}

void delete_element(Node* head, int valueToBeDeleted){
	struct Node* temp = head;
	while (temp != NULL){
		if(temp->data == valueToBeDeleted){
			
			//if node to be removed is @ head
			if(temp==head)
			{
			//dereferencing head pointer bc its a copy (pass by value)
			//access the actual value and change it to the head next value
			*head = *(head->next);
 			  head->prev = NULL;
			  free(head->next->prev);
			  head->next->prev = head;
				return;
        
			}
			
			//if node to be removed is @ tail 
			if(temp->next == NULL){
				temp->prev->next=NULL;
       				 break;
			}

			temp->next->prev= temp->prev;
			temp->prev->next= temp->next;
     			 break;
		}
		temp=temp->next;
	}
  free(temp);
  return;
}

void sort_dll (Node* head){
	int ifSwapped, i;

	struct Node* runner;
	struct	Node* temp= NULL;

	if (head == NULL)
		return;

	do
	{
		ifSwapped =0;
		runner = head;

		while( runner->next != temp){
			if (runner->data > runner->next->data)
			{
				int temp = runner->data;
				runner->data = runner->next->data;
				runner->next->data =temp;

				ifSwapped =1;
			}
			runner = runner->next;
		}
		temp = runner;
	}
		while (ifSwapped);
}

void freeList(struct Node* deleteMe){
	if(deleteMe == NULL)
  {
    return;
  }
  else
  {
    Node* next = deleteMe->next;
    free(deleteMe);
    freeList(next);
  }
}


int main ()
{
	int array[5]= {11,2,7,22,4};
	 Node* head;

	 /*Question 1*/
	 head = create_dll_from_array(array,5); //size of array is 5
	 
	/*Question 2*/
	print_dll(head);
	 
	/*Question 3*/
	insert_after(head, 7,13);
	insert_after(head,21,29);
	print_dll(head);

	/*Question 4*/
	delete_element(head,22);
	print_dll(head);
	delete_element(head,11);	
 	print_dll(head);

	/*Question 5*/
	sort_dll(head);
	print_dll(head);
	
	/*Question 6*/ 
	freeList(head);

	return 0;
}

















