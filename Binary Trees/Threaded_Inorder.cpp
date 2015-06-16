//http://ideone.com/6amuc9
//Threaded Binary tree - Inorder traversal
//Mood : <Jugaad!!>

#include<iostream>

using namespace std;

//Structure of each node in the threaded tree
struct node{
	
	int data;
	node *left;
	node *right;
	bool rthread;
	
};

node* newNode( int d ){
	
	node *n = new node;
	n -> data = d;
	n -> left = n -> right = NULL;
	n -> rthread = 0;
	
	
	return n;
}

node* leftmost( node *root ){
	
	node *temp = root;
	
	if( temp == NULL )
		return NULL;
	
	while( temp -> left )
		temp = temp -> left;
	
	return temp;
	
}

void inorderThreaded( node *root ){
	
	node *cur = leftmost(root);
	
	while( cur != NULL ){
		
		cout<<cur -> data<<" ";
		
		if( cur -> rthread )
			cur = cur -> right;
		else
			cur = leftmost(cur -> right);
			
	}
	
}

int main(){
	
	node *root = newNode(6);	
	
	root -> left = newNode(3);
	root -> right = newNode(8);
	
	root -> left -> left = newNode(1);
	root -> left -> left -> right = root -> left;
	root -> left -> left -> rthread = 1;
	
	root -> left -> right = newNode(5);
	root -> left -> right -> rthread = 1;
	root -> left -> right -> right = root;
	
	root -> right -> left = newNode(7);
	root -> right -> left -> rthread = 1;
	root -> right -> left -> right = root -> right;
	
	
	root -> right -> right = newNode(11);
	
	root -> right -> right ->left = newNode(9);
	root -> right -> right ->left -> rthread = 1;
	root -> right -> right ->left -> right = root -> right -> right;
	
	root -> right -> right -> right = newNode(13);
	
	inorderThreaded(root);
	
	return 0;	
	
}
