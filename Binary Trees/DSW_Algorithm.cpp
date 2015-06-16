//http://ideone.com/gnRh8H
//DSW Algorithm

#include <iostream>
#include<cmath>

using namespace std;

struct node{

	int data;
	node *left;
	node *right;
	
};

node* newNode( int d ){
	
	node *nn = new node;
	nn -> data = d;
	nn -> left = nn -> right = NULL;
	
	return nn;
	
}

void BST_Insert( node** root, int d ){
	
	node *p = *root;
	node *prev = NULL;
	
	while( p ){
		
		prev = p;
		
		if( d < p -> data )
			p = p -> left;		
	
		else
			p = p -> right;
			
	}
	
	if( *root == NULL )
		*root = newNode(d);
	
	else if( d < prev -> data )
		prev -> left = newNode(d);
	else
		prev -> right = newNode(d);
	
}

void rightRotate( node* G , node* P , node* C ){	//G:Grandparent , P:Parent , C:Child
	
	node *temp1,*temp2;
	
	temp1 = (C)->right;
	temp2 = (P);
	
	(G) -> right = C;
	temp2 -> left = temp1;
	(C) -> right = temp2;

}

void createBackbone( node* root ){
	
	node* par = root;
	node* gp = NULL;
	node* prev = NULL;
	
	while( par ){
		
		prev = par;
		
		if( par->left ){
			
			rightRotate(gp,par,par->left);
			par = gp->right;
			
		}
		else{
			par = par->right;
			gp = prev;
		}
		
	}
	
}

void createPerfectTree( node* root , int n ){
	
	int m = pow(2,log2(n+1))-1;
	
	for( int i = 0 ; i < n-m ; i++ ){
		
		//Right rotate
	}
	while( m > 1 ){
			
			m = m/2;
			//Right rotate m times
			
	}
	
}

void inorder( node *root ){
	
	if( !root )
		return;
	
	inorder( root->left );
	cout<<root->data<<" ";
	inorder( root->right );
	
}

int main() {
	// your code goes here
	
	node *root = NULL;
	BST_Insert( &root , 5 );
	BST_Insert( &root , 10 );
	BST_Insert( &root , 20 );
	BST_Insert( &root , 15 );
	BST_Insert( &root , 30 );
	BST_Insert( &root , 25 );
	BST_Insert( &root , 40 );
	BST_Insert( &root , 23 );
	BST_Insert( &root , 28 );
	
	//rightRotate( root->right , root->right->right , root->right->right->left );
	
	//inorder( root );
	createBackbone(root);
	inorder( root );
	/*while( root->right ){
		cout<<root->data<<" ";
		root = root->right;
	}*/
	return 0;

}
