//http://ideone.com/dhKznQ
//Foldable binary trees

#include <iostream>
using namespace std;

struct node{

	int data;
	node* left;
	node* right;
	
};

node* newNode( int d ){
	
	node *nn = new node;
	nn -> data = d;
	nn -> left = nn -> right = NULL;
	
	return nn;
	
}

bool foldable( node *n1 , node* n2 ){
	
	if( n1 == NULL && n2 == NULL )
		return 1;
	
	if( n1 == NULL || n2 == NULL )
		return 0;
	
	return foldable( n1 -> left , n2 -> right ) && foldable( n1 -> right , n2 -> left );
	
}

bool isFoldable( node *root ){
	
	if( !root )
		return 1;
	
	return foldable( root -> left , root -> right );	

}

int main() {
	// your code goes here

	node *root = newNode(1);	
	
	root -> left = newNode(2);
	root -> right = newNode(3);
	
	root -> left -> left = newNode(4);
	root -> right -> right = newNode(5);
	
	if( isFoldable(root) )
		cout<<"Tree is foldable!";
	else
		cout<<"Tree isnt foldable";

	return 0;

}
