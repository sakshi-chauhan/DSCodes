//http://ideone.com/vFP5AG
//Print ancestors of a binary tree w/o recursion

#include <iostream>
#include <stack>
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

void printAncestors( node* root , int key ){
	
	if( root == NULL )
		return;
	
	stack<node*> stk;
	
	while(1){
		
		while( root && (root -> data != key) ){
		
			stk.push(root);
			root = root -> left;
		
		}
		
		if( root && root -> data == key )
			break;
		
		if( stk.top()->right == NULL ){
			
			root = stk.top();
			stk.pop();
			
			while( !stk.empty() && stk.top() -> right == root ){
			
				root = stk.top();
				stk.pop();
				
			}
			
		}
		
		root = stk.empty()?NULL:stk.top()->right;
	}
	
	while( !stk.empty() ){
		
		cout<<stk.top()->data<<" ";
		stk.pop();
		
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

	printAncestors( root , 40 );

	return 0;

}
