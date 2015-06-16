//http://ideone.com/QCn4bh
//Diameter of a binary tree
//Mood: <Bemann!!>

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

int max( int a , int b ){
	
	return a>b?a:b;

}

int height( node *root ){
	
	if( root == NULL )
		return 0;
	
	else
		return max( height(root->left) , height(root -> right) ) + 1;
	
}

int diameter( node* root ){
	
	if( root == NULL )
		return 0;
	
	int lheight = height( root -> left ); 
	int rheight = height( root -> right );
	
	int ld = diameter( root -> left );
	int rd = diameter( root -> right );
	
	return max(max(ld,rd),lheight+rheight+1);
	
}

int main() {
	// your code goes here
	
	node *root = create(1);	
	
	root -> left = create(2);
	root -> right = create(3);
	
	root -> left -> left = create(4);
	root -> left -> right = create(5);
	
	cout<<diameter(root);
	
	return 0;
	
}
