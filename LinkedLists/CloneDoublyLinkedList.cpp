//http://ideone.com/XGFFtn
//Cloning a linked list

#include <iostream>

struct node{
	
	int data;
	node *next;
	node *arbit;
	
};

void printList( node *head ){
	
	node *cur = head;
	
	while( cur != NULL ){
		
		std::cout<<cur->data<<" + "<<cur -> arbit -> data <<" -> ";
		cur = cur->next;
	
	}
	
	std::cout<<"NULL\n";

}


//Inserts a node at the beginning of the linked list, doesn't set the arbit pointer
void insert( node **head , int d ){
	
	node *nn = new node;
	nn -> data = d;
	nn -> next = NULL;
	nn -> arbit = NULL;
	
	if( *head == NULL ){
		
		*head = nn;
		return;
		
	}
	
	nn -> next = *head;
	*head = nn;
}

node* clone ( node *head ){
	
	node *head_clone = NULL;
	node *cur;
	node *nn , *temp;
	
	cur = head;
	
	while( cur != NULL ){
	
		nn = new node;	
		nn -> data = cur -> data;
		nn -> next = NULL;
		
		if( head_clone == NULL ){
		
			head_clone = nn;
			temp = head_clone;
			
		}
		
		else{
			
			temp -> next = nn;		
			temp = temp -> next;
			
		}
		
		cur = cur -> next;
		
	}
	
	
	cur = head;
	temp = head_clone;
	
	while( cur ){
		
		nn = cur -> next;
		
		cur -> next = temp;	
		temp -> arbit = cur;
		
		cur = nn;
		temp = temp -> next;
	
	}
	
	temp = head_clone;
	
	while( temp ){
		
		temp -> arbit = temp -> arbit -> arbit -> next;
		temp = temp -> next;
		
	}
	
	return head_clone;
	
}

int main() {
	// your code goes here
	
	node *head = NULL;
	
	insert( &head , 5 );
	insert( &head , 4 );
	insert( &head , 3 );
	insert( &head , 2 );
	insert( &head , 1 );
	
	//printList( head );
	
	head -> arbit = head -> next -> next;
	head -> next -> arbit = head;
	head -> next -> next -> arbit = head -> next -> next -> next -> next;
	head -> next -> next -> next -> arbit = head -> next -> next;
	head -> next -> next -> next -> next -> arbit = head -> next;
	
	
	node *dup = clone( head ); 
	
	printList( dup );
	
	return 0;

}
