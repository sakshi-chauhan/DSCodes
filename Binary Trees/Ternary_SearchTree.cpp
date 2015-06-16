//http://ideone.com/iPNS1M
//Implementation of a ternary search tree

#include <iostream>
using namespace std;

struct node{
	
	char data;
	unsigned eof:1;
	node *left;
	node *right;
	node* eq;
	
};

node* newNode( char ch ){
	
	node *n = new node;
	n -> data = ch;
	n -> eof = 0;
	n -> left = n -> eq = n -> right = NULL;
	
	return n;
}

void insert_TST( node** root , char* word ){
	
	if( !*root )
		*root = newNode( *word );
		
	if( *word < (*root) -> data) 
		insert_TST( &(*root)->left , word );
	
	else if( *word > (*root)->data )
		insert_TST( &(*root)->right , word );

	else{
		
		if( *(word +1) )
			insert_TST( &(*root)->eq , word+1 );
		else
			(*root)->eof = 1;
		
	}	
	
}

bool search_TST( node* root , char * word ){
	
	if( !root )
		return 0;
	
	if( *word < root -> data )
		search_TST( root->left , word );
	
	else if( *word > root -> data )
		search_TST( root->right , word );
	
	else{
		
		if( *(word+1) == '\0' )
			return root->eof;
		
		return search_TST( root->eq , word+1 );	
		
	}	
	
} 



int main() {
	// your code goes here
	
	node* root = NULL;
	insert_TST( &root , "cats" );
	
	if( search_TST(root,"cat") )
		cout<<"Match found";
	else
		cout<<"Not matched";
		
	return 0;

}
