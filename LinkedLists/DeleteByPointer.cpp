//http://ideone.com/vrA7S6
//Given only a pointer to the node to be deleted, delete the node
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
	
}

int DeleteByPointer( node *n ){
	
	int el = n->data;
	
	n->data = n->next->data;
	n -> next = n -> next -> next;
	
	delete( n->next );
	
	return el;
}

int main(){
	
	node *head = NULL;
	insert( &head , 12 );
	insert( &head , 2 );
	insert( &head , 26 );
	insert( &head , 32 );
	insert( &head , 50 );
	printlist( head );
	
	std::cout<<"\nDeleted node has data "<<DeleteByPointer( head->next )<<"\n";
	printlist( head );
	
}
