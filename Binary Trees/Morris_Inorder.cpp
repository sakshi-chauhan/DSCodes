//http://ideone.com/wbSA40
//Morris Inorder traversal - doesnt use a stack/threads

#include <iostream>
using namespace std;

struct node{
	
	int data;
	node *left;
	node *right;
	
};

node* create( int d ){
	
	node *nn = new node;
	nn -> data = d;
	nn -> left = nn -> right = NULL;
	
	return nn;
	
}

void morrisInorder( node *root ){
	
	node *cur, *temp;
	
	cur = root;
	
	while( cur != NULL ){
		
		if( cur -> left == 0 ){
			
			cout<<cur -> data<<" ";
			cur = cur -> right;
			
		}
		else{
			
			temp = cur -> left;
			
			while( temp -> right != NULL && temp -> right != cur )
				temp = temp -> right;
				
			if( temp -> right == NULL ){
				
				temp -> right = cur;
				cur = cur -> left;
				
			}
			else{
				
				cout<<cur->data<<" ";
				temp -> right = NULL;
				cur = cur -> right;
			
			}
		}
		
	}
	
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
	
	root -> right -> left -> left = create(8);
	root -> right -> left -> right  = create(9);
	
	root -> right -> right -> left = create(10);
	root -> right -> right -> right = create(11);

	morrisInorder(root);

	return 0;

}
