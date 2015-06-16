//http://ideone.com/8vgF6i
//Implementing a doubly linked list

#include<iostream>

struct node{

	int data;
	node *next;
	node *prev;
	
};

void printList( node *head ){
	
	node *cur = head;
	
	while( cur != NULL ){
		
		std::cout<<cur->data<<" <-> ";
		cur = cur->next;
		
	}
	
	std::cout<<"NULL\n";
	
}

void insert_beg( node **head , int d ){
	
	node *nn = new node;
	nn -> data = d;
	nn -> prev = NULL;
	
	if( *head == NULL ){
		
		nn -> next = NULL;
		(*head) = nn;
		return;
		
	}
	
	
	nn -> next = (*head);
	
	(*head) ->prev = nn;
	
	(*head) = nn;
	
}

void insert_end( node **head , int d ){
	
	node *nn = new node;
	nn -> data = d;
	nn -> next = NULL;
	
	if( *head == NULL ){
		
		nn -> prev = NULL;
		*head = nn;
		return;
		
	}
	
	node *cur = *head;
	
	while( cur -> next != NULL )
		cur = cur -> next;
	
	cur -> next = nn;
	nn -> prev = cur;	
}

void deleteNode( node **head , node *del ){
	
	if( *head == NULL || del == NULL ){
		
		std::cout<<"The list is empty cannot delete a node!!";
		return;
		
	}
	
	if( del == *head ){
	
		*head = del -> next;
		delete(del);
		return;
	
	}
	
	if( del -> next != NULL ){
		
		del -> prev -> next = del -> next;
	
	}
	if( del -> prev != NULL ){
		
		if( del -> next )
			del -> next -> prev = del -> prev;
		else
			del -> prev -> next = NULL;
	}
	
	delete(del);	
	return;
}

int main(){
	
	node *head = NULL;
	
	/*insert_beg( &head , 5 );
	insert_beg( &head , 2 );
	insert_beg( &head , 3 );*/
	
	insert_end( &head , 5 );
	insert_end( &head , 2 );
	insert_end( &head , 3 );
	
	printList( head );
	
	deleteNode( &head , head );
	
	printList( head );
	
	return 0;
	
}
