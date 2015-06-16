//http://ideone.com/AxgGHG
//Remove duplicates from a sorted linked list
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

void RemoveDuplicatesSorted( node *head ){
	
	node *temp = head;
	node *next_ptr;
	
	while( temp->next != NULL ){
		
		next_ptr = temp -> next;
		
		if( temp -> data == next_ptr -> data ){
			
			temp -> next = next_ptr -> next;
			delete( next_ptr );			
		}
		else{
			
			temp = temp -> next;
			
		}	
	}
	
}

int main(){
	
	node *head = NULL;
	insert( &head , 50 );
	insert( &head , 50 );
	insert( &head , 50 );
	insert( &head , 42 );
	insert( &head , 26 );
	insert( &head , 22 );
	insert( &head , 5 );
	insert( &head , 5 );
	printlist( head );

	RemoveDuplicatesSorted( head );
	printlist( head );

}
