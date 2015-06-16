//http://ideone.com/J8KMjx
//Find nth node of the linked list

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

int getnnode( node *head , int n ){
	
	node *temp = head;
	int k = 1;
	
	if ( n == 1 )
		return head->data;
	
	else{
		
		while( temp != NULL && k < n ){
			
			temp = temp -> next;
			k++;
			
		}	
		return temp->data;
	}	
	
}


int main(){
	
	node *head = NULL;
	insert( &head , 12 );
	insert( &head , 2 );
	insert( &head , 26 );
	insert( &head , 32 );
	insert( &head , 50 );
	printlist( head );
	
	std::cout<<"\nNth node = "<<getnnode( head , 3);
}
