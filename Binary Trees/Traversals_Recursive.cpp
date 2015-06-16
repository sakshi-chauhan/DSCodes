//http://ideone.com/0Z1cOC
//Tree traversals (recursive)
//Mood : <bring it on, LIFE>
/* tree is like this - 
		1
	   / \	
	  2   3
	 / \ / \
	4  5 6  7 

*/
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
	nn -> left = NULL;
	nn -> right = NULL;
	
	return nn;

}


//Inorder traversal of tree - Left Node Right
void inorder( node *root ){
	
	if( root == NULL )
		return;
	
	inorder( root -> left );
	
	cout<<root -> data<<" ";
	
	inorder( root -> right );
	
}

//Preorder traversal of a tree - Node Left Right
void preorder( node *root ){
	
	if( root == NULL )
		return;
	
	cout<<root -> data<<" ";
	
	preorder( root -> left );
	preorder( root -> right );
	
}

//Postorder traversal of a tree - Left Right Node
void postorder( node * root ){
	
	if( root == NULL )
		return;
	
	postorder( root -> left );
	postorder( root -> right );
	
	cout<<root -> data<<" ";
	
}

int main() {
	// your code goes here

	node *root = create(1);
	root -> left = create(2);
	root -> right = create(3);
	
	root -> left -> left = create(4);
	root -> left -> right = create(5);
	
	root -> right -> left = create(6);
	root -> right -> right = create(7);

	cout<<"Inorder traversal \n";
	inorder(root);
	
	cout<<"\nPreorder traversal \n";
	preorder(root);

	cout<<"\nPostorder traversal \n";
	postorder(root);
	return 0;

}
