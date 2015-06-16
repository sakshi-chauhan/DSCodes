//http://ideone.com/RSU0x2
//Morris traversal for preorder

#include <iostream>
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

void MorrisPreorder( node* root ){
	
	while( root ){
		
		if( root->left == 0 ){
			
			cout<<root->data<<" ";
			root = root->right;
			
		}
		else{
			
			node* temp = root->left;
			
			while( temp->right && temp->right != root)
				temp = temp -> right;
			
			
			if( temp->right == root ){
				
				temp->right = 0;
				root = root->right;
				
			}
			else{
				
				cout<<root->data<<" ";
				temp -> right = root;
				root = root->left;
				
			}	
			
		}
		
	}
	
}

void preorder( node *root ){
	
	if( !root )
		return;
	
	cout<<root->data<<" ";
	preorder( root->left );
	preorder( root->right ); 
	
}

int main() {
	// your code goes here

	node *root = newNode(1);	
	
	root -> left = newNode(2);
	root -> right = newNode(3);
	
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
	
	MorrisPreorder( root );
	cout<<'\n';
	preorder( root );
	
	return 0;

}
