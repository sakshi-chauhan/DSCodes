//http://ideone.com/H9fsOZ
//Check if some path in the tree has a given sum

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

bool hasSum( node *root , int sum ){
	
	if( root == 0 )
		return sum==0;
	
	else{
		
		int sub = sum - root -> data;
		bool ans = 0;
		
		if( sub == 0 && root -> left == NULL && root -> right == NULL )
			return 1;
		
		if( root -> left )
			ans = ans || hasSum( root -> left , sub );
		
		if( root -> right )
			ans = ans || hasSum( root -> right , sub );
		
		return ans;
		
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
	
	root -> right -> left -> left = create(8);
	root -> right -> left -> right  = create(9);
	
	root -> right -> right -> left = create(10);
	root -> right -> right -> right = create(11);
	
	int sum;
	cin>>sum;
	
	if( hasSum(root,sum) )
		cout<<"Path with sum = "<<sum<<" exits.";
	
	else
		cout<<"No path with sum = "<<sum;
	
	return 0;

}
