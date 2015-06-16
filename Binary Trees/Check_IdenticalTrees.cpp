//http://ideone.com/xugqUa
//Determine if two trees are identical
//Mood : <Buck up!!>

#include<iostream>

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

bool isIdentical( node *root1 , node *root2 ){
	
	if( root1 == NULL && root2 == NULL )
		return 1;
	
	else{
		
		return (root1->data==root2->data && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right) );
		
	}
	
	return 0;	
}

int main(){
	
	node *root1 = create(1);
	root1 -> left = create(15);
	root1 -> right = create(23);
	
	node *root2 = create(1);
	root2 -> left = create(15);
	root2 -> right = create(2);
	
	if( isIdentical( root1 , root2 ) )
		cout<<"Both the trees are identical";
	else
		cout<<"Different!!";
	
	return 0;
	
}
