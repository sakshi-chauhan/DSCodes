//http://ideone.com/trPnre
//Merge Sort

#include <iostream>

struct node{
	
	int data;
	node *next;

};

node* SortedMerge( node *a , node *b );
void Split( node* , node** , node** );

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

void MergeSort( node **head ){
	
	node *start = *head ;
	node *a;
	node *b;
	
	if( start == NULL || start->next == NULL )
		return;
		
	Split( start , &a , &b );	
	
	
	MergeSort( &a );
	MergeSort( &b );
	
	
	*head = SortedMerge(a,b);
}

node* SortedMerge( node *a , node *b ){
	
	node *res = NULL;
	
	if( a == NULL )
		return b;
	
	if( b == NULL )
		return a;
		
	if( a -> data <= b -> data ){
		
		res = a;
		res -> next = SortedMerge( a->next , b );
	
	}
	
	else{
		
		res = b;
		res -> next = SortedMerge( a, b->next );
		
	}
	return res;
}

void Split( node *source , node **first , node **second ){
	
	struct node* fast;
  	struct node* slow;
  
  	if (source==NULL || source->next==NULL){
    
    	*first = source;
    	*second = NULL;
    	
  	}
  	
  else{
  	
    	slow = source;
    	fast = source->next;

    	while (fast != NULL){
      
      		fast = fast->next;
      		if (fast != NULL){
        
        		slow = slow->next;
        		fast = fast->next;
      		}
    	}
 
    
    *first = source;
    *second = slow->next;
     slow->next = NULL;
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

	MergeSort( &head );
	printlist( head );
	return 0;
	
}
