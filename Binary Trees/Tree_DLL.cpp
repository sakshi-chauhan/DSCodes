//http://ideone.com/6upCr8
//Convert tree to DLL | Set 2

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

void setLeftPointers( node* root ){
	
	if( root == NULL )
		return;
	
	static node* pre = NULL;
	
	setLeftPointers( root -> left );
	
	root -> left = pre;
	//if(pre)
	//cout<<root->data<<"left set to "<<pre->data;
	pre = root;
	
	setLeftPointers( root -> right );
	
}

node* setRightPointers( node* root ){
	
	while( root && root->right )
		root = root -> right;
		
	node* pre = NULL;
	
	while( root ->left ){
		
		pre = root;
		root = root -> left;
		root -> right = pre;
		
	}
	
	return root;
	
}

void printList( node* root ){
	
	node* temp = root;
	
	while( temp ){
		
		cout<<temp->data<<" ";
		temp = temp -> right;
		
	}
	cout<<'\n';
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
	
	setLeftPointers(root);
	//cout<<root->data;
	//printList(root);
	node* res = setRightPointers(root);
	printList(res);
	
	return 0;

}
