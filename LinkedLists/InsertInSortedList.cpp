//http://ideone.com/UzWGpR
//Program to insert in a linked list

#include <iostream>

struct node{
	
	int data;
	node *next;

};


void insert( node **head , int d ){
	
	node *newnode = new node;
	newnode->data = d;
	newnode->next = *head;
	
	*head = newnode;
	
}

void printlist( node *head ){
	
	node *p = head;
	
	while( p != NULL ){
		
		std::cout<<p->data<<" -> ";
		p = p->next;
	}
	std::cout<<"NULL\n";
}

void InsertInSortedList( node **head , int el ){
	
	node *nn = new node;
	nn -> data = el;
	
	
	if( *head == NULL || el <= (*head)->data ){
		
		nn -> next = *head;
		*head = nn;
		
	}
	
	else{
		
		node *p = *head;
		
		while( p != NULL && p->next->data < el )
			p = p -> next;
			
		nn->next = p->next;
		p->next = nn;
		
	}
}


int main(){
	
	node *head = NULL;
	insert( &head , 50 );
	insert( &head , 42 );
	insert( &head , 26 );
	insert( &head , 22 );
	insert( &head , 5 );
	printlist( head );
	
	InsertInSortedList( &head , 20 );
	InsertInSortedList( &head , 2 );
	printlist( head );
}
