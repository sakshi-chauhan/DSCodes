//http://ideone.com/VfZTRq
//Binary Tree | Set 1
//Mood : <Scared>
/*    1
	/   \
   2     3
  / \
 4  5
 
*/

#include<iostream>

//Structure of each node in the tree
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

int main(){
	
	node *root = newNode(1);	
	
	root -> left = newNode(2);
	root -> right = newNode(3);
	
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
		
	return 0;	
	
}
