//http://ideone.com/Lw36Ft
//Construct special binary tree from given inorder traversal

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

int max_array( int* arr , int start , int end ){
	
	int max = arr[start];
	int pos = start;
	
	for( int i = start ; i <= end ; i++ ){
		
		if( arr[i] > max ){
			
			max = arr[i];
			pos = i;
			
		}
		
	}
	return pos;
}

node* inorderToBinary( int* in , int start , int end ){
	//cout<<"I2B ";
	if( start > end )
		return NULL;
	
	int m = max_array( in , start , end );
	//cout<<"Max pos = "<<m;
	
	node *root = newNode(in[m]);	
	
	if( start == end )
		return root;
	
	root -> left = inorderToBinary( in , start , m-1 );
	root -> right = inorderToBinary( in , m+1 , end );
	
	return root;

}

void inorder( node *root ){
	
	if( root == NULL )
		return; 
	
	inorder( root->left );
	cout<<root->data<<" ";
	inorder( root->right );
	
}

int main() {
	// your code goes here

	int n;
	cin>>n;
	int *arr = new int[n];
	
	for( int i = 0 ; i < n ;i++ )
		cin>>arr[i];
	
	node* root = inorderToBinary(arr, 0 , n-1);	
	inorder(root);
	
	return 0;

}
