//http://ideone.com/f58OCY
//Merge two sorted linked lists

#include<iostream>

void MoveNode(struct node** destRef, struct node** sourceRef);

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

node* MergeList( node *head1 , node *head2 ){
	
	node dummy;
	
	node *tail = &dummy;
	
	dummy.next = NULL;
	
	while( 1 ){
		
		if( head1 == NULL ){
			
			tail -> next = head2;
			break;
			
		}
		
		else if ( head2 == NULL ) {
         	
         	tail->next = head1;
         	break;
      	}
      	
      	if ( head1->data <= head2->data ) {
      		
         	MoveNode(&(tail->next), &head1);
      	
      	}
      	
      	else{
        
        	MoveNode(&(tail->next), &head2);
        	
     	}
     	tail = tail->next;
	}
	
	return (dummy.next);
}

void MoveNode(struct node** destRef, struct node** sourceRef){
	
	node* newNode = *sourceRef;
	*sourceRef = newNode->next;
    newNode->next = *destRef; 
  	*destRef = newNode;
  	
}

int main(){
	
	node *head1,*head2,*res;
	
	insert( &head1 , 7 );
	insert( &head1 , 5 );
	insert( &head1 , 3 );
	insert( &head1 , 1 );
	printlist( head1 );
	
	insert( &head2 , 8 );
	insert( &head2 , 6 );
	insert( &head2 , 4 );
	insert( &head2 , 2 );
	printlist( head2 );
	
	
	res = MergeList( head1 , head2 );
	printlist(res);
}
