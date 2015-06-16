//http://ideone.com/VgvNM9
//Check if one tree is a subtree of another

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

bool isIdentical( node *root1 , node *root2 ){
	
	if( root1 == NULL && root2 == NULL )
		return 1;
	
	if( root1 == NULL || root2 == NULL )
		return 0;
	
	return (root1->data == root2->data && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right));
}

//Is the tree rooted at root2 a subtree of the tree rooted at root1 
bool isSubTree( node *root1 , node *root2 ){
	
	if( root1 == NULL )
		return 0;
	
	if( root2 == NULL )
		return 1;
	
	if( isIdentical( root1,root2 ))
		return 1;
	
	return isSubTree(root1->left,root2)||isSubTree(root1->right,root2);	
	
}

int main() {
	// your code goes here
	
	node *root = newNode(26);	
	
	root -> left = newNode(9);
	root -> right = newNode(4);
	
	root -> left -> left = newNode(2);
	root -> left -> right = newNode(7);
	root -> right -> right = newNode(1);
	root -> right -> left = newNode(3);
	
	node *head = newNode(9);
	head -> left = newNode(2);
	head -> right = newNode(7);
	
	if( isSubTree(root,head) )
		cout<<"Yeahh!!";
	
	else
		cout<<"Noo";
	
	return 0;
}
