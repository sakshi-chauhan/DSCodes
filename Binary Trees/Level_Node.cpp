//http://ideone.com/G1OMNC
//Get level of a node in a binary tree

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

int level( node* root , int data , int l ){
	
	if( root == NULL )
		return 0;
	
	if( root -> data == data )
		return l;
	
	
	int lvl = level(root->left,data,l+1);
	
	if( lvl )
		return lvl;
	
	lvl = level(root->right,data,l+1);	
	return lvl;

}

int getLevel( node *root , int data ){
	
	return level( root , data , 1 );
	
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
	
	cout<<getLevel( root , 7);

	return 0;

}
