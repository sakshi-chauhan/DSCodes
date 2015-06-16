//http://ideone.com/8az5UQ
//Check if the list is a palindrome

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
	std::cout<<"NULL\n";
}

void reverseList( node **head ){
	
	node *p,*q,*r;
	
	p = NULL;
	q = *head;
	
	while( q != NULL ){
		
		r = q -> next;
		q -> next = p;
		p = q;
		q = r;
		
	}
	
	*head = p;
}

bool compareList( node *head1 , node *head2 ){
	
	node *temp1,*temp2;
	temp1 = head1;
	temp2 = head2;
	
	while( temp1 && temp2 ){
		
		if( temp1->data == temp2->data ){
			
			temp1 = temp1->next;
			temp2 = temp2->next;
			
		}
		else
			return 0;
		
	}
	
	if( temp1 == NULL && temp2 == NULL )
		return 1;
	
	return 0;	
	
}

bool isPalindrome( node *head ){
	
	node *slow , *fast , *prev_slow , *mid , *second;
	bool flag;
	
	slow = fast = prev_slow = head;
	mid = NULL;
	
	while( fast && fast->next ){
		
		prev_slow = slow;
		slow = slow->next;
		fast = fast->next->next;
		
	}
	
	
	if( fast != NULL ){
		
		mid = slow;
		slow = slow->next;
		
	}
	
	second = slow;
	prev_slow->next = NULL;
	
	reverseList( &second );
	
	if( compareList( head , second ) )
		flag = 1;
	else
		flag = 0;
		
	if( fast != NULL ){
		
		prev_slow -> next = mid;
		mid -> next = second;
		
	}
	else
		prev_slow -> next = second;
		
		
	return flag;	
}

int main(){
	
	node *head = NULL;
	insert( &head , 12 );
	insert( &head , 2 );
	insert( &head , 26 );
	insert( &head , 2 );
	insert( &head , 12 );
	printlist( head );
	
	
	if( isPalindrome( head ) )
		std::cout<<"Palindrome";
	else
		std::cout<<"Not a palindrome";
}
