//http://ideone.com/0rCIXX
//Determine if a  tree is height balanced

#include <iostream>
#include<cmath>

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

int max( int a , int b ){
	
	return a>b?a:b;
	
}

int height( node *root ){
	
	if( root == NULL )
		return 0;
	
	return max( height(root->left) , height(root->right) )+1;

}

bool balanced( node *root ){
	
	if( root == NULL )
		return 1;
		
	int lh,rh;
	lh = height( root -> left );
	rh = height( root -> right );
	
	if( abs(lh-rh)<=1 && balanced(root->left) && balanced( root -> right ) )
		return 1;
	
	return 0;
	
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
	
	root -> right -> left -> left = create(8);
	//root -> right -> left -> right  = create(9);
	
	root -> right -> right -> left = create(10);
	//root -> right -> right -> right = create(11);

	if( balanced(root) )
		cout<<"Tree is height balanced";
	else
		cout<<"Not height balanced";
		
	
	return 0;

}
