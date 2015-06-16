//http://ideone.com/YEYJwV
//Construct the tree from given inorder and preorder traversals

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

int search( int *arr , int beg , int end , int item ){
	
	for( int i = beg ; i < end ; i++ ){
		
		if( arr[i] == item )
			return i;
		
	}
	return -1;
	
}

node* buildTree( int *pre , int *in , int inStart ,int inEnd ){
	
	static int preIndex = 0;
	
	if( inStart > inEnd )
		return NULL;
	
	node *tnode = create( pre[preIndex++] );
	
	if( inStart == inEnd )
		return tnode;
	
	int inIndex = search( in , inStart , inEnd , tnode->data );
	
	tnode -> left = buildTree( pre , in , inStart , inIndex - 1 );
	tnode -> right = buildTree( pre , in , inIndex + 1 , inEnd );
	
	return tnode;
	
}


int main() {
	// your code goes here
	return 0;
}
