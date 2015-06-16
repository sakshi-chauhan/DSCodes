//http://ideone.com/e3aD1X
//Tree traversals - Iterative
//Mood - <Josh!>

#include <iostream>
#include <stack>
using namespace std;

struct node{

	int data;
	node *left;
	node *right;
	
};

node* create( int d ){
	
	node *nn = new node;
	nn -> data = d;
	nn -> left = NULL;
	nn -> right = NULL;
	
	return nn;

}

//Preorder traversal - Node Left Right : Use a stack
void preorder( node *root ){
	
	stack<node*> stk;
	node *p = root;
	
	if( p != NULL ){
		
		stk.push(p);
		
		while( !stk.empty() ){
			
			p = stk.top();
			stk.pop();
			cout<<p->data<<" ";
			
			if( p -> right )
				stk.push( p -> right );
				
			if( p -> left )
				stk.push( p -> left );
			
		}
		
	}

}

//Post order using preoder: just reverse the sequence obtained inright to left preorder traversal
//Uses 2 stacks
void postorder( node *root ){
	
	stack<node*> stk;
	stack<int> stk2;
	node *p = root;
	
	if( p != NULL ){
		
		stk.push(p);
		
		while( !stk.empty() ){
			
			p = stk.top();
			stk.pop();
			
			stk2.push(p -> data);
			//cout<<p->data<<" ";
			
			if( p -> left )
				stk.push( p -> left );
			
			if( p -> right )
				stk.push( p -> right );
				
		}
		
	}
	
	while( !stk2.empty() ){
		
		cout<<stk2.top()<<" ";
		stk2.pop();
		
	}

}

//The other side of postorder - one stack being used
void postorderIterative( node *root ){
	
	stack<node*> stk;
	node *p = root;
	node *q = root;
	
	while( p ){
		
		for( ; p -> left ; p = p->left )
			stk.push(p);
		
		while( p -> right == NULL || p -> right == q ){
			
			cout<<p->data<<" ";
			q = p;
			
			if( stk.empty() )
				return;
			
			p = stk.top();
			stk.pop();
			
		}
		
		stk.push(p);
		p = p -> right;
		
	}
	
}

void inorder( node *root ){
	
	stack<node*> stk;
	node *p = root;
	
	while( p ){
		
		while( p ){	
			
			if( p -> right )
				stk.push( p -> right);
			
			stk.push(p);
			
			p = p -> left;
			
		}
		
		p = stk.top();
		stk.pop();
		
		while( p -> right == 0 && !stk.empty() ){
			
			cout<<p->data<<" ";
			
			p = stk.top();
			stk.pop();
			
		}
		
		cout<<p->data<<" ";
		
		if( !stk.empty() ){
			p = stk.top();
			stk.pop();
		}
		
		else
			p = 0;
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

	cout<<"Inorder traversal \n";
	inorder(root);
	
	cout<<"\nPreorder traversal \n";
	preorder(root);

	cout<<"\nPostorder traversal \n";
	//postorder(root);
	postorderIterative(root);
	
	return 0;

}
