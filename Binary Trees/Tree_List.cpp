//http://ideone.com/wogeaX
//Tree list problem
//Mood : <Subha hogyi Mamu!!>

#include<iostream>
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

void join( node *a , node *b ){
	
	a -> right = b;
	b -> left = a;
	
}

node* append( node *a , node *b ){
	
	node *aleft;
	node *bleft;
	
	if( a == NULL )
		return b;
	
	if( b == NULL )
		return a;
	
	aleft = a -> left;
	bleft = b -> left;
	
	join(aleft,b);
	join(bleft,a);
	
	return a;
	
}

node* treeToList( node *root ){
	
	if( root == NULL )
		return NULL;
	
	node *alist,*blist;
	
	alist = treeToList( root -> left );
	blist = treeToList( root -> right );
	
	root -> left = root;
	root -> right = root;
	
	alist = append( alist,root );
	blist = append( alist,blist );
	
	return alist;
}

void printList( node *head ) {
	
    node *current = head;
    
    while(current != NULL) {
        
        cout<<current->data<<" ";
        current = current->right;
        if (current == head) 
        	break;
        
    }
    
}

int main(){
	
	node *root = newNode(4);	
	
	root -> left = newNode(2);
	root -> right = newNode(5);
	
	root -> left -> left = newNode(1);
	root -> left -> right = newNode(3);
	
	node *res = treeToList(root);
	
	printList(res);
	
	return 0;	
	
}
