//http://ideone.com/4QZsKK
//Ancestors of a node in a binary tree

#include <iostream>
using namespace std;

struct node{
	
	int data;
	node* left;
	node* right;
	
};

node* newNode( int d ){
	
	node* nn = new node;
	nn -> data = d;
	nn -> left = nn -> right = NULL;
	
	return nn;
	
}

bool printAncestors( node* root , int target ){
	
	if( root == NULL )
		return 0;
	
	if( root -> data == target )
		return 1;
		
	if( printAncestors( root -> left , target ) || printAncestors( root -> right , target ) ){
		
		cout<<root->data<<" ";
		return 1;
	
	}
	
	return 0;
}

int main() {
	// your code goes here
	
	node *root = newNode(1);	
	
	root -> left = newNode(2);
	root -> right = newNode(3);
	
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(6);
	root -> right -> right = newNode(5);
	root -> right -> left = newNode(7);	
	
	printAncestors(root,7);
	
	return 0;

}
