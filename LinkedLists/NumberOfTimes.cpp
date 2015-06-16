//http://ideone.com/FmKmFo
//Number of times a given int appears in a linked list

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
	std::cout<<"\n";
}

int NTimes( node *head , int e ){
	
	node *temp = head;
	int count = 0;
	
	while( temp != NULL ){
		
		if( temp -> data == e )
			count++;
			
		temp = temp->next;
		
	}
	
	return count;
	
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
	
	std::cout<<NTimes( head , 1);
}
