//http://ideone.com/QarYo1
//Reverse using recursion

#include <iostream>

using namespace std;

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

node* reverse( node *head, node *prev ){
     
     if( head->next == NULL )
         return head;
     
     prev = head;
     head = head->next;
     head = reverse( head , prev ); 
    
     head->next = prev;
     cout<<head->data<<"->next = "<<prev->data;    	 
     return prev;
    
}

int main(){
    
    node* head;
    insert( &head,5 );
    insert( &head,4 );
    insert( &head,3 );
    insert( &head,2 );
    insert( &head,1 );
    
    printlist(head);
    
    head = reverse( head , NULL );
    
    //printlist(head);
    
    return 0;
        
}
