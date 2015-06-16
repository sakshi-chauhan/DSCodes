//http://ideone.com/KjfDxr
//Find height of a binary tree iteratively

#include <iostream>
#include <queue>

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

int height( node* root ){
	
	if( root == NULL )
		return 0;
	
	queue<node*> q;
	q.push(root);
	
	int ht = 0;
	
	while(1){
		
		int node_count = q.size();
		
		if( node_count == 0 )
			return ht;
		else
			ht++;
		
		while( node_count > 0 ){
			
			node* n = q.front();
			q.pop();
			
			if( n -> left )
				q.push( n->left );
			
			if( n -> right )
				q.push( n -> right );
			
			node_count--;
		}	
		
		
	}
	
	
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
	
	cout<<height(root);
	
	return 0;

}
