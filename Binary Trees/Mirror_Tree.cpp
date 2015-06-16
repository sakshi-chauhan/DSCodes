//http://ideone.com/gTj3uC
//Convert a tree into its mirror tree
//Mood : <recursion god, be kind>

#include <iostream>
#include<queue>

using namespace std;

struct node{

	int data;
	node *left;
	node *right;
	
};

node* create( int d ){
	
	node *nn= new node;
	nn -> data = d;
	nn -> left = nn -> right = NULL;
	
	return nn;
	
}

void mirrorify( node *root ){
	
	if( root == NULL )
		return;
	
	mirrorify( root -> left );
	mirrorify( root -> right );
	
	node *temp = root -> left;
	root -> left = root -> right;
	root -> right = temp;
	
}

void BFS( node *root ){
	
	queue<node*> q;
	node *p = root;
	
	if( p ){
		
		q.push(p);
		
		while( !q.empty() ){
			
			p = q.front();
			q.pop();
			cout<<p->data<<" ";
			
			if( p -> left )
				q.push( p -> left );
			
			if( p -> right )
				q.push( p -> right );
				
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

	BFS(root);
	
	mirrorify(root);
	
	BFS(root);
	
	return 0;
}
