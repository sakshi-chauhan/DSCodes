//http://ideone.com/cnGrVq
//Print Nth node from the end of a linked list

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

void PrintNthFromEnd( node *head , int n ){
	
	node *temp = head;
	int len = 0;
	
	while( temp != NULL ){
		
		len++;
		temp = temp -> next;
		
	}
	
	if( len < n )
		return;
	
	temp = head;
 
  
    for ( int i = 1; i < len-n+1; i++ )
       temp = temp->next;
 
    std::cout<<"Nth node has data"<<temp->data;
 
    return;	
}

int main(){
	
	node *head = NULL;
	insert( &head , 12 );
	insert( &head , 2 );
	insert( &head , 26 );
	insert( &head , 32 );
	insert( &head , 50 );
	printlist( head );
	
	PrintNthFromEnd( head , 2 );
	
}
