//http://ideone.com/90ldfl
//Reverse level order traversal

#include <iostream>
#include <stack>
#include <queue>

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

void reverseLevelOrder( node* root ){
	
	stack<node*> stk;
	queue<node*> q;
	
	q.push(root);
	
	while( !q.empty() ){
		
		root = q.front();
		q.pop();
		stk.push(root);
		
		if( root->right )
			q.push( root->right );
		
		if( root->left )
			q.push( root->left );
		
	}
	
	while( !stk.empty() ){
		
		cout<<stk.top() -> data<<" ";
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
	
	reverseLevelOrder(root);
	
	return 0;

}
