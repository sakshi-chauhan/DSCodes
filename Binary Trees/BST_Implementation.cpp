//http://ideone.com/vHFyMo
//Implementing Binary Search Trees
 
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
 
struct node{
 
	int data;
	node *left;
	node *right;
 
};
 
node* newNode( int d ){
 
	node *nn = new node;
	nn -> data = d;
	nn -> left = nn -> right = NULL;
 
	return nn;
 
}
 
void BST_Insert( node** root, int d ){
 
	node *p = *root;
	node *prev = NULL;
 
	while( p ){
 
		prev = p;
 
		if( d < p -> data )
			p = p -> left;		
 
		else
			p = p -> right;
 
	}
 
	if( *root == NULL )
		*root = newNode(d);
 
	else if( d < prev -> data )
		prev -> left = newNode(d);
	else
		prev -> right = newNode(d);
 
}
 
void BST_DeletebyMerging( node*& n ){
 
	node *temp = n;
 
	if( n != 0 ){
 
		if( !n->right )
			n = n -> left;
 
		else if( !n->left )
			n = n -> right;
 
		else{
 
			temp = n -> left;
 
			while( temp -> right )
				temp = temp -> right;
 
			temp -> right = n -> right;
			temp = n;
			n = n ->left;
 
		}
		delete temp;
	}
 
}
 
void BST_DeletebyCopying(node*& n){
 
	node *prev,*temp = n;
 
	if( !n -> right )
		n = n -> left;
 
	else if( !n ->left )
		n = n -> right;
 
	else{
 
		temp = n->left;
		prev = n;
 
		while( temp->right ){
 
			prev = temp;	
			temp = temp->right;
 
		}
 
		n -> data = temp ->data;	
 
		if( prev == n )
			prev->left = temp->left;
		else
			prev->right = temp->left;
 
	}	
 
}
 
 
void inorder( node *root ){
 
	if( !root )
		return;
 
	inorder( root->left );
	cout<<root->data<<" ";
	inorder( root->right );
 
}
 
int main() {
	// your code goes here
 
	node *root = NULL;
	BST_Insert( &root , 1 );
	BST_Insert( &root->left , 2 );
	BST_Insert( &root->right , 3 );
 
	//BST_DeletebyMerging(root);
	BST_DeletebyCopying(root);
	inorder( root );
 
	return 0;
 
}
