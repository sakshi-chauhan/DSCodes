//http://ideone.com/MP0AK0
//Function to reverse a linked list

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

void reverseList( node **head ){
	
	node *p,*q,*r;
	
	p = NULL;
	q = *head;
	
	while( q != NULL ){
		
		r = q -> next;
		q -> next = p;
		p = q;
		q = r;
		
	}
	
	*head = p;
}

int main(){
	
	node *head = NULL;
	insert( &head , 12 );
	insert( &head , 12 );
	insert( &head , 12 );
	insert( &head , 2 );
	insert( &head , 26 );
	insert( &head , 32 );
	insert( &head , 50 );
	printlist( head );
	
	reverseList(&head);
	
	printlist( head );
}
