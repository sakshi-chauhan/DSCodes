//http://ideone.com/U2oLS1
//Add two numbers represented by linked lists | SET 2

#include<iostream>
#include<cstdlib>

struct node{
	
	int data;
	node *next;

};

int getSize( node *head ){
	
	int len = 0;
	node *cur = head;
	
	while( cur != NULL ){
		
		len++;
		cur = cur -> next;
		
	}
	
	
	return len;
	
}

void swapPointers( node **head1 , node **head2 ){
	
	node *temp = *head1;
	*head1 = *head2;
	*head2 = temp;
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


//If the lists are same size use this utility
node* AddSameSize( node *head1 , node *head2 , int *carry ){
	
	if( head1 == NULL )
		return NULL;
	
	node *res = new node;
	int sum;
	
	res -> next = AddSameSize( head1 -> next , head2 -> next , carry );
	
	sum = head1->data + head2->data + *carry ;
	 
	*carry = sum/10;
	sum %= 10;
	
	res -> data = sum;
	
	return res; 
}

//Adds remaining terms after the same sized portions have already been added
void AddRemainingList( node *head1 , node *cur , int *carry , node **res ){
	
	int sum;
	
	if( head1 != cur ){
		
		AddRemainingList( head1 -> next , cur , carry , res);
		
		sum = head1 -> data + *carry ;
		*carry = sum / 10;
		sum %= 10;
		
		insert( res , sum );
	}
	
}

void AddLists( node *head1 , node *head2 , node **res ){
	
	if( head1 == NULL ){
	
		*res = head2;
		return;
		
	}
	
	if( head2 == NULL ){
	
		*res = head1;
		return;
		
	}
	
	int l1 = getSize( head1 );
	int l2 = getSize( head2 );
	int carry = 0;
	
	if( l1 == l2 )
		*res = AddSameSize( head1 , head2 , &carry );
		
	else{
		
		int diff = abs( l1 - l2 );
		//std::cout<<l1<<"  "<<l2<<"  "<<diff<<"\n"; 
		
		if( l1 < l2 )
			swapPointers( &head1 , &head2 );
		
		node *cur;
		
		for( cur = head1 ; diff-- ; cur = cur -> next );
		
		*res = AddSameSize( cur , head2 , &carry );	
		AddRemainingList( head1 , cur , &carry , res );
	}	
	
	if( carry )
		insert( res , carry);
}

int main(){
	
	node *head1,*head2,*res;
	int carry = 0;
	
	
	insert( &head1 , 4);
	insert( &head1 , 4);
	insert( &head1 , 4);
	insert( &head1 , 4);
	//printlist( head1 );
	
	insert( &head2 , 0);
	insert( &head2 , 2);
	//insert( &head2 , 2);
	//insert( &head2 , 2);
	//printlist( head2 );
	
	//res = AddSameSize( head1 , head2 , &carry );
	//printlist( res );
	
	AddLists( head1 , head2 , &res );
	printlist( res );
	
	return 0;
	
}
