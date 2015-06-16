//http://ideone.com/n8ARam
//Delete alternate nodes of a linked list

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

void DeleteAlternate( node *head ){
	
	node *temp;
	node *to_be_deleted;
	
	temp = head;
	
	while( temp -> next != NULL ){
		
		to_be_deleted = temp -> next;
		
		if( to_be_deleted -> next != NULL ){
			
			temp -> next = to_be_deleted -> next;
			temp = temp -> next;
			
		}
		
		else
			temp->next = NULL;
			
		delete( to_be_deleted );	
	}
	
}
int main(){
	
	node *head = NULL;
	insert( &head , 7 );
	insert( &head , 6 );
	insert( &head , 5 );
	insert( &head , 4 );
	insert( &head , 3 );
	insert( &head , 2 );
	insert( &head , 1 );
	printlist( head );

	DeleteAlternate( head );
	printlist( head );

}

