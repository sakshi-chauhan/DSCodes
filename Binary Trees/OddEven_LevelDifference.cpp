//http://ideone.com/dHEZqC
//Print difference of sum of odd and even levels

#include <iostream>
#include <queue>
using namespace std;

struct node{
	
	int data;
	node* left;
	node* right;
	
};

node* newNode( int d ){
	
	node* nn = new node;
	nn -> data = d;
	nn -> left = nn -> right = NULL;
	
	return nn;
	
}

// Find node difference using level order traversal
int printDifference( node* root ){
	
	queue<node*> q;
	node* temp;
	int odd_sum = 0;
	int even_sum = 0;
	bool flag = 0;
	bool child = true;
	
	q.push(root);
	q.push(NULL);
	
	while( !q.empty() ){
		
		temp = q.front();
		q.pop();
		
		if( temp && !(temp->left) && !(temp->right) )
			child = false;
			
		//child = false;
	
		if( !temp ){
			flag = 1-flag;
			q.push(NULL);
			
			if( !child )
				break;
		}
		
		else{
			//child = false;	
			if( flag )
				even_sum += temp->data;
				
			else
				odd_sum += temp->data;
				
			if( temp -> left ){
				
				q.push( temp -> left );
				child = true;
			
			}
			
			if( temp -> right ){
			
				q.push( temp -> right );
				child = true;
			
			}
			
		}	
		
	}
	
	return odd_sum - even_sum;
}

int main() {
	// your code goes here
	
	node* root = newNode(10);
	
	root->left = newNode(5);
	root->right = newNode(12);
	
	root->left->left = newNode(16);
	root->left->right = newNode(8);
	
	root->right->left = newNode(21);
	root->right->right = newNode(40);
	
	root->right->right->right = newNode(80);

	cout<<printDifference(root);	
	
	return 0;

}
