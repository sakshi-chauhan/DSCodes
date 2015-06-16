//http://ideone.com/uBHk9L
//Check if a given binary tree a sum tree

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

int sum( node* root ){
	
	if( !root )
		return 0;
	
	return sum( root->left ) + root->data + sum( root->right );	
	
}

bool isSumTree( node *root ){
	
	if( root == NULL || ( root->left == NULL && root->right==NULL ))
		return 1;
	
	return (root->data == sum(root->left)+sum(root->right) && isSumTree(root->left) && isSumTree(root->right));	
	
}

int main() {
	// your code goes here

	node *root = newNode(26);	
	
	root -> left = newNode(9);
	root -> right = newNode(4);
	
	root -> left -> left = newNode(2);
	root -> left -> right = newNode(7);
	root -> right -> right = newNode(1);
	root -> right -> left = newNode(3);	
	
	if( isSumTree(root) )
		cout<<"It's a sum tree";
	else
		cout<<"Not a sum tree";
		
	return 0;

}
