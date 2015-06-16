//http://ideone.com/tVb5bj
//Construct a binary tree from given preorder and postorder traversals 

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
/*pre - preorder array 
post - postorder array
preIndex - index into the preorder array
l , h - bounds of the current array
size - size of the array
*/
node* constructBinaryTree( int* pre , int* post , int* preIndex , int l , int h , int size ){
	
	if( *preIndex >= size || l > h )
		return NULL;
	
	node* root = newNode( pre[*preIndex] );
	++*preIndex;
	
	if( l == h )
		return root;
	
	int i;
	for( i = l ; i <= h ; i++ )
		if( post[i] == pre[*preIndex] )
			break;
	
	if( i <= h ){
		
		root -> left = constructBinaryTree( pre , post , preIndex , l , i , size );
		root -> right = constructBinaryTree( pre , post , preIndex , i+1 , h , size );
		
	}
	
	return root;
	
}

void inorder( node* root ){
	
	if(root){
		
		inorder( root->left );
		cout<<root->data<<" ";
		inorder( root->right );
		
	}
	
}

int main() {
	// your code goes here

	int n;
	int* pre;
	int* post;
	
	cin>>n;
	pre = new int[n];
	post = new int[n];

	for( int i = 0 ; i < n ; i++ )
		cin>>pre[i];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>post[i];
		
	int preIndex = 0;
	node* root = constructBinaryTree( pre, post, &preIndex , 0 , n-1 , n);
	inorder(root);
	
	return 0;
	
}
