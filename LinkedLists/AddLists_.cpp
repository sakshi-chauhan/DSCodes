//http://ideone.com/BkUH7Y
//Add two numbers represented by linked lists

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

node *AddTwoLists( node *head1 , node *head2 ){
	
	node *head3 = NULL; 	//points to the resultant list
	node *temp,*start;
	int sum , carry = 0 ;
	
	
	while( head1 != NULL && head2 != NULL ){
		
		sum = (head1 -> data) + (head2 -> data) + carry ;
		temp = new node;
		
		if( sum > 10 ){
			
			sum = sum % 10;
			carry = 1;
			
		}
		
		//std::cout<<"Sum is = "<<sum<<"\n";
		
		temp -> data = sum;
		temp -> next = NULL;
		
		//std::cout<<"Sum is = "<<temp->data<<"\n";
		
		if( head3 == NULL ){
		
			head3 = temp ;
			start = head3;
			head3 -> next = NULL;
			
			//std::cout<<"Sum is = "<<head3->data<<"\n";
		
		}
		
		else{
			
			head3 -> next = temp;
			//std::cout<<"Sum is = "<<head3->next->data<<"\n";
			head3 = head3->next;
			
		}
		head1 = head1 -> next;
		head2 = head2 -> next;
		
		
	}
	
	if( head1 != NULL ){
		
		while( head1 != NULL ){
			
			temp = new node;
			temp -> data = head1 -> data;
			temp -> next = NULL;
			
			
			head3 -> next = temp;
			head3 = head3->next;
			head1 = head1 -> next;
		}
		
	}
	
	if( head2 != NULL ){
		
		while( head2 != NULL ){
			
			temp = new node;
			temp -> data = head2 -> data;
			temp -> next = NULL;
			
			
			head3 -> next = temp;
			head3 = head3 -> next;
			head2 = head2 -> next;
		}
		
	}
	
	
	return start;
	
}

int main(){
	
	node *head1,*head2,*res;
	
	insert( &head1 , 3 );
	insert( &head1 , 2 );
	insert( &head1 , 1 );
	
	insert( &head2 , 3 );
	//insert( &head2 , 3 );
	//insert( &head2 , 3 );
	
	res = AddTwoLists( head1 , head2 );
	
	printlist( res );
	
	return 0;
}
