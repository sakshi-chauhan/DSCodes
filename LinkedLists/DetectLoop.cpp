//http://ideone.com/lt4hSA
//Detect a loop in a linked list
//FLOYD'S CYCLE FINDING ALGORITHM

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

bool detectCycle( node *head ){
	
	node *fast,*slow;
	fast = slow = head;
	
	while( fast && slow && fast->next ){
		
		slow = slow -> next;
		fast = fast -> next -> next;
		
		if( slow == fast )
			return 1;
		
	}
	
	return 0;
}

int main(){
	
	node *head = NULL;
	insert( &head , 12 );
	insert( &head , 2 );
	insert( &head , 26 );
	insert( &head , 32 );
	insert( &head , 50 );
	printlist( head );
	
	head -> next -> next -> next -> next -> next = head -> next;
	
	if( detectCycle( head ) )
		std::cout<<"There's a loop in the list";
	
	else
		std::cout<<"No LOOP";
	
	//printlist( head );
}
