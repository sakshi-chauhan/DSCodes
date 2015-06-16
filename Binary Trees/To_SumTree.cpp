//http://ideone.com/8LSs66
//Convert a tree into sum tree

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

int toSumTree( node* root ){
	
	if( root == NULL )
		return 0;
		
	int oldData = root -> data;
	
	root -> data = toSumTree( root -> left ) + toSumTree( root -> right );
	
	return oldData + root -> data;
}

void inorder( node *root ){
	
	if( root == NULL )
		return;
		
	inorder( root -> left );
	cout<<root->data<<" ";
	inorder( root -> right );
	
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
	
	inorder( root );
	cout<<'\n';
	toSumTree( root );
	inorder( root );
	
	return 0;

}
