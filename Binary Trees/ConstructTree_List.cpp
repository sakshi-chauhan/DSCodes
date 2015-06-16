//http://ideone.com/julGtA
//Construct tree from linked representation

#include <iostream>
#include <queue>
using namespace std;

struct node_list{
	
	int el;
	node_list* next;
	
};

struct node_tree{

	int data;
	node_tree* left;
	node_tree* right;
	
};

node_tree* newTreeNode( int d ){
	
	node_tree* nn = new node_tree;
	nn -> data = d;
	nn -> left = nn -> right = NULL;
	
	return nn;
	
}

void insert( node_list** head , int e){
	
	node_list* nn = new node_list;
	nn -> el = e;
	nn -> next = *head;
	
	*head = nn;
	
}

void printList( node_list* head ){
	
	node_list* temp = head;
	
	while( temp ){
		
		cout<<temp->el<<" ";
		temp = temp->next;
		
	}
	
}

void constructTree( node_tree*& root , node_list* head ){
	
	if( head == NULL ){
		
		root = NULL;
		return;
		
	}
	
	queue<node_tree*> q;	
	root = newTreeNode( head -> el );
	
	q.push(root);
	
	head = head -> next;
	
	while( head ){
		
		node_tree* parent = q.front();
		q.pop();
		
		node_tree *leftchild = NULL ,*rightchild = NULL;
		
		leftchild = newTreeNode( head -> el );
		q.push(leftchild);
		head = head -> next;
		
		if( head ){
			
			rightchild = newTreeNode( head->el );
			q.push(rightchild);
			head = head -> next;
			
		}
		
		parent -> left = leftchild;
		parent -> right = rightchild;
		
	}
	
}

void inorder( node_tree* root ){
	
	if( !root )
		return;
		
	inorder( root->left );
	cout<<root->data<<" ";
	inorder( root->right );
	
}

int main() {
	// your code goes here
	
	node_list* head = NULL;
	
	insert( &head , 36 );
	insert( &head , 30 );
	insert( &head , 25 );
	insert( &head , 15 );
	insert( &head , 12 );
	insert( &head , 10 );
	
	//printList(head);
	
	node_tree* root;
	
	constructTree( root , head );
	inorder(root);
	
	return 0;

}
