//http://ideone.com/yiRFth
//Find maximum depth of a tree
//Mood : <recursion god, give me strength>

#include <iostream>
using namespace std;

struct node{

	int data;
	node *left;
	node *right;
	
};

node* create( int d ){
	
	node *nn= new node;
	nn -> data = d;
	nn -> left = nn -> right = NULL;
	
	return nn;
	
}

int max( int a , int b ){
	
	return a>b?a:b;
	
}

int maximumDepth( node *root ){
	
	if( root == 0 )
		return 0;
	else
		return max( maximumDepth(root->left),maximumDepth(root->right))+1;
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
	
	cout<<maximumDepth(root);
	
	return 0;

}
