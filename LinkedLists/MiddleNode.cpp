//http://ideone.com/2wOAna
//Find middle node of the linked list

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

int MiddleNode( node *head ){
	
	node *slow, *fast;
	slow = head;
	fast = head;
	
	while( fast != NULL && fast->next != NULL ){
		
		fast = fast -> next -> next;
		slow = slow -> next;
		
	}
	
	return slow -> data;
}

int main(){
	
	node *head = NULL;
	insert( &head , 12 );
	insert( &head , 2 );
	insert( &head , 26 );
	insert( &head , 32 );
	insert( &head , 50 );
	printlist( head );
	
	std::cout<<"\nMiddle node has data "<<MiddleNode(head);
}
