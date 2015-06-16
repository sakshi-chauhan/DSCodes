//http://ideone.com/hNJx15
//Convert an arbitrary tree into a height balanced tree
//Mood : <Bass!!>

#include <iostream>

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

void increment( node* n , int diff ){
	
	//Increment the left child by diff
	if( n -> left ){
		
		n -> left -> data = n -> left -> data + diff;
		increment( n -> left , diff );
	
	}
	
	//In case there's no left child, increment the right child
	else if( n -> right ){
		
		n -> right -> data = n -> right -> data + diff;
		increment( n -> right , diff );
		
	}
	
}

void convert( node *root ){
	
	if( root == NULL || ( (root -> left == NULL) && (root -> right == NULL) ) )
		return;
		
	else{
		
		int ldata = 0;
		int rdata = 0;
		int diff;
		
		convert( root -> left );
		convert( root -> right );
		
		if( root -> left )
			ldata = root -> left -> data;
		
		if( root -> right )
			rdata = root -> right -> data;
		
		diff = root -> data - ( ldata + rdata );
		
		if( diff < 0 )
			root -> data = root -> data - diff;
		
		if( diff > 0 )
			increment( root , diff );
	}	
}

void inorder( node *root ){
	
	if( root == NULL )
		return;
	
	inorder( root -> left );
	cout<<root->data<<" ";
	inorder(root -> right);
	
}


int main() {
	// your code goes here

  node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);

  inorder( root );
  cout<<'\n';	
  convert( root );
  inorder( root );
  
  return 0;

}
