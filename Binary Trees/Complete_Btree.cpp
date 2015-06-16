//http://ideone.com/Uej7PX
//Linked complete binary tree - Implementation

#include <iostream>
#include<queue>

using namespace std;

struct node{
	
	int data;
	node *left;
	node *right;
	
};

node* newNode( int d ){
	
	node *n = new node;
	n -> data = d;
	n -> left = n -> right = NULL;
	
	return n;
}

void insert( node** root , int el , queue<node*> q){
	
	if( !*root ){
	
		*root = newNode( el );
		q.push(*root);
		return;
	
	}
	
	node *temp = newNode( el );
	node *f = q.front();
	
	if( f -> left == 0 ){
		
		f ->left = temp;
		
	}
	else if( f ->right == 0 ){
		
		f ->right = temp;
		
	}
	
	else{
		
		q.pop();
		
	}	
	q.push(temp);
}

int main() {
	// your code goes here

	node *root = newNode(1);	
	
	root -> left = newNode(2);
	root -> right = newNode(3);
	
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	
	queue<node*> q;
	
	
	insert( &root , 1 , q );
	insert( &root , 2 , q );
	cout<<root->data<<" "<<root->left->data;
	return 0;

}
