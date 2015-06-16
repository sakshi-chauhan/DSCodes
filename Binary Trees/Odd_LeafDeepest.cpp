//http://ideone.com/2ET9B3
//Depth of deepest odd level leaf noded

#include <iostream>
#include <algorithm>
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

int printOddLeaf( node* root , int level ){
	
	if( root == NULL )
		return 0;
	
	
	if( root->left == NULL && root -> right == NULL && level&1 )
		return level;
	
	return max( printOddLeaf( root -> left , level + 1 ) , printOddLeaf( root -> right , level) );	
	
}


int main() {
	// your code goes here
	
	node* root = newNode(10);
	
	root->left = newNode(5);
	root->right = newNode(12);
	
	root->left->left = newNode(16);
	root->left->right = newNode(8);
	
	root->right->left = newNode(21);
	root->right->right = newNode(40);
	
	root->right->right->right = newNode(80);	
	
	cout<<printOddLeaf( root , 1 );
	return 0;

}
