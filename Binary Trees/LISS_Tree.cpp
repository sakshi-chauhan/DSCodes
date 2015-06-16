//http://ideone.com/u6k35s
//Largest Independent set problem

#include <iostream>
using namespace std;

struct node{
	
	int data;
	node* left;
	node* right;
	
};

node* newNode( int el ){
	
	node* nn = new node;
	
	nn -> data = el;
	nn -> left = nn -> right = NULL;
	
	return nn;
	
}

int LISS( node* root ){
	
	if( root == NULL )
		return 0;
		
	int size_ex = LISS(root->left) + LISS(root->right);
	
	int size_in = 1;
	
	if( root->left ){
		
		size_in += LISS(root->left->left) + LISS(root->left->right);
		
	}
	if( root->right ){
		
		size_in += LISS(root->right->left) + LISS(root->right->right);
	}
	
	return size_in;
	
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
	
	cout<<LISS(root);
	
	return 0;

}
