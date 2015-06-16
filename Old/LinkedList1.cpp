#include<iostream>

template<class T>
struct node{
       
       T data;            
       struct node* next;
       
};

template<class T>
void print_list(struct node<T>* n){

     while( n != NULL ){
            
            std::cout<<n->data<<" ";
            n = n->next;
                   
     }
            
}

int main(){
    
    struct node<int> *nn = new struct node<int>;    
    nn->data = 23;
    nn->next = '\0';
    
    print_list(nn);
    
    return 0;
}
