//http://ideone.com/L0L0GX
//Detect and remove loop from a linked list

#include <iostream>

struct node{
	
	int data;
	node *next;

};

void RemoveLoop( node* , node* );

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

bool DetectRemoveLoop( node* head ){
	
	node *slow,*fast;
	
	
	slow = fast = head;
	
	while( fast && fast -> next ){
		
		slow = slow -> next;
		fast = fast -> next -> next;
		
		if( slow == fast ){
			
			RemoveLoop( slow , head );
			return 1;
			
		}
		
	}
	
	return 0;
}

void RemoveLoop( node *loop_node , node *head ){
	
	node *p1,*p2;
	
	
	p1 = head;
	
	while(1){
		
		p2 = loop_node;
		
		while( p2 -> next != p1 && p2 -> next != loop_node ){
			
			p2 = p2 -> next;
			
		}
		
		if( p2 -> next == p1 )
			break;
		
		else
			p1 = p1 -> next;
	}
	
	p2->next = NULL;
}


int main(){
	
	
	node *head;
	
	insert(&head,5);
	insert(&head,4);
	insert(&head,3);
	insert(&head,2);
	insert(&head,1);
	
	printlist( head );
	
	head -> next -> next -> next -> next -> next = head -> next -> next;
	//printlist( head );
	
	if( DetectRemoveLoop( head ) )
		std::cout<<"Loop detected and removed\n";
	else
		std::cout<<"No loop present\n";
		
	printlist( head );
	
	return 0;
	
}
