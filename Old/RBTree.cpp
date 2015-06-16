#include<iostream>

struct node{
       
       node* p;     
       node* left;
       node* right;
       int key;
       char color;
       
};

class RBT{
      
      //node* root;       
      public:
             node* root;
             RBT(){
                   root = NULL;      
             }
             void RBTInsert( node* T , node* z );
             void LeftRotate( node* T , node* x );
             void RightRotate( node* T , node* x );
             void RBTFixup( node* T , node* z );
             void Inorder(node* T);
};
  
void RBT::RBTInsert( node* T , node* z ){
     
     node* y = new node;
     node* x = new node;
     y = NULL;
     x = root;
     
     while( x != NULL ){
            
            y = x;
            
            if( z->key < x->key )
                x = x->left;       
            else
                x = x->right;
           
     }
     
     z->p = y;
     
     if( y == NULL )
         root = z;
     else if( z->key < y->key )
         y->left = z;
     else
         y->right = z;
         
     z->left = NULL;
     z->right = NULL;
     z->color = 'R';
     
     //RBTFixup(T,z);                 
     
}

void RBT::LeftRotate( node* T , node* x ){
     node* y = new node;
     
     y = x->right;
     x->right = y->left;
     
     if( y->left != NULL )
         y->left->p = x;
     
     y->p = x->p;
     
     if( x->p == NULL )
         root = y;
     
     else if( x == x->p->left )
         x->p->left = y;
     
     else
         x->p->right = y;
     
     y->left = x;
     x->p = y;                 
     
}

void RBT::RightRotate( node* T , node* x ){
     node* y = new node;
     
     y = x->left;
     x->left = y->right;
     
     if( y->right != NULL )
         y->right->p = x;
     
     y->p = x->p;
     
     if( x->p == NULL )
         root = y;
     
     else if( x == x->p->left )
         x->p->left = y;
     
     else
         x->p->right = y;
     
     y->right = x;
     x->p = y;                 
     
}

void RBT::RBTFixup(node* T , node* z){
	
	node *y;
	while( z->p->color == 'R' ){
		
		if( z->p == z->p->p->left ){
			
			y= z->p->p->right;
			
			if( y->color == 'R' ){
				
				z->p->color ='B';
				y->color = 'B';
				z->p->p->color = 'R';
				z = z->p->p;
				
			}
			
			else if( z == z->p->right ){
				
				z = z->p;
				LeftRotate(T,z);
				
			}
			
			else if( z == z->p->left ){
				
				z->p->color = 'B';
				z->p->p->color = 'R';
				RightRotate(T,z->p->p);
			}
		}
		
		else{
			
			y= z->p->p->left;
			
			if( y->color == 'R' ){
				
				z->p->color ='B';
				y->color = 'B';
				z->p->p->color = 'R';
				z = z->p->p;
				
			}
			
			else if( z == z->p->left ){
				
				z = z->p;
				LeftRotate(T,z);
				
			}
			
			else if( z == z->p->right ){
				
				z->p->color = 'B';
				z->p->p->color = 'R';
				RightRotate(T,z->p->p);
			}

		}
		
	}
	root->color = 'B';
}

void RBT::Inorder( node * T){
     if( T == NULL )
         return;
     
     Inorder(T->left);    
     std::cout<<T->key<<" ";
     Inorder(T->right);
}

int main(){
    
    //RBT* T = new RBT;
    RBT T;
    
    node* z = new node;
    z->key = 23;
    z->p = z->left = z->right = NULL;
    T.RBTInsert(T.root,z);
    T.Inorder(T.root);
    return 0;    
    
}
