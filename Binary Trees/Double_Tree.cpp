//http://ideone.com/7UX6yM
//Double tree 

#include <iostream>
using namespace std;

struct node{
	
	int data;
	node *left;
	node *right;
	
};

node* create( int d ){
	
	node *nn = new node;
	nn -> data = d;
	nn -> left = nn -> right = NULL;
	
	return nn;
	
}

void doubleTree( node *root ){
	
	if( root == NULL )
		return;
	
	doubleTree( root -> left );
	doubleTree( root -> right );
	
	node *old = root -> left;
	root ->left = create( root -> data );
	root -> left -> left = old;

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
	
	node *root = create(1);	
	
	root -> left = create(2);
	root -> right = create(3);
	
	root -> left -> left = create(4);
	root -> left -> right = create(5);

	inorder(root);
	cout<<'\n';
	doubleTree(root);
	inorder(root);
	
	return 0;

}
