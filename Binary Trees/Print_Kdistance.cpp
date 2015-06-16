//http://ideone.com/TBZ0o9
//Print nodes at distance K(given) from the root

#include <iostream>
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

void printKDistance( node* root , int k ){
	
	if( root == NULL )
		return;
	
	if( k == 0 ){
		
		cout<<root -> data<<" ";
		return;
	
	}
	
	printKDistance( root -> left , k - 1 );
	printKDistance( root -> right , k - 1 );

}

int main() {
	// your code goes here
	
	node *root = newNode(1);	
	
	root -> left = newNode(2);
	root -> right = newNode(3);
	
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(6);
	root -> right -> right = newNode(5);
	root -> right -> left = newNode(7);
	
	printKDistance( root , 2 );	
	
	return 0;

}
