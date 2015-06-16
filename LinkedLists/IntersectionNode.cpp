//http://ideone.com/wl3M31
//Find intersection point of two linked lists

#include <iostream>

struct node{
	
	int data;	
	node *next;
	
};

int Intersection( int , node* , node* );

int listLength( node *head ){
	
	node *temp = head;
	int len = 0;
	
	while( temp != NULL ){
		
		len++;
		temp = temp -> next;
	
	}
	
	return len;
}

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

int getIntersectionNode( node *head1 , node *head2 ){
	
	int len1 = listLength( head1 );
	int len2 = listLength( head2 );
	
	int d;
	
	if( len1 > len2 ){
		
		d = len1 - len2;
		return Intersection( d , head1 , head2 ); 
		
	}
	else{
		
		d = len2 - len1;
		return Intersection( d , head2 , head1 ); 
	
	}	
}

int Intersection( int d , node *head1 , node *head2 ){
	
	node *temp1 = head1;
	node *temp2 = head2;
	
	
	for( int i = 0 ; i < d ; i++ ){
		
		if( temp1 == NULL )
			return -1;
		
		temp1 = temp1 -> next;
		
	}
	
	while( temp1 != NULL && temp2 != NULL ){
		
		if( temp1 == temp2 )
			return temp1->data;
		
		temp1 = temp1->next;
		temp2 = temp2->next;
		
	}
	
	return -1;
}

int main(){
	
  node* newNode;
  node* head1 = new node;
            
  head1->data  = 10;
 
  node* head2 = new node;
            
  head2->data  = 3;
 
  newNode = new node;
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = new node;
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = new node;
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = new node;
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  std::cout<<"The node of intersection is "<<getIntersectionNode(head1, head2);
 
  return 0;	
}
