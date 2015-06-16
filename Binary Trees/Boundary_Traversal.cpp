//http://ideone.com/gLcLxa
//Boundary level traversal of a tree

#include <iostream>
using namespace std;

struct node{
	
	int data;
	node *left;
	node *right;
	
};

node* newNode( int d ){
	
	node *n = new node;
	n -> data = d;
	n -> left = n -> right = NULL;
	
	return n;
}

void printLeaves( node* root ){
	
	if(root){
		
		printLeaves( root -> left );
		
		if( !root->left && !root->right )
			cout<<root->data<<" ";
		
		printLeaves( root->right );
	
	}
	
}

//Nodes on the left boundary are to be printed in a top-down manner
void printLeftBoundary( node* root ){
	
	if(root){
		
		if( root->left ){
			
			cout<<root->data<<" ";
			printLeftBoundary( root->left );
		
		}
		else if( root->right ){
			
			cout<<root->data;
			printLeftBoundary( root->right );
		
		}
		
	}
	
}

//Nodes on the right boundary are to be printed in a Bottom-Up manner
void printRightBoundary( node* root ){
	
	if( root ){
		
		if( root -> right ){
			
			printRightBoundary( root -> right );
			cout<<root->data<<" ";
			
		}
		else if( root->left ){
			
			printRightBoundary( root->left );
			cout<<root->data;
		
		}
	
	}
	
}

void printBoundary( node* root ){
	
	if( root ){
		
		cout<<root->data<<" ";
		
		printLeftBoundary( root->left );
		
		printLeaves( root->left );
		printLeaves( root->right );
	
		printRightBoundary( root -> right );
		
	}

}


int main() {
	// your code goes here
	
	node *root = newNode(1);	
	
	root -> left = newNode(2);
	root -> right = newNode(3);
	
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);

	//printLeaves(root);
	cout<<"Boundary level traversal --\n";
	printBoundary(root);
	
	return 0;

}
