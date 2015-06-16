//Iterative reverse w/o using built in functions

#include<iostream>
using namespace std;

void IterativeReverse(){
     
     char stack[80];
     int top = 0;
     cin.get( stack[top] );
     
     while( stack[top] != '\n' )
            cin.get( stack[++top] );
            
     for( top -= 1 ; top >= 0 ; cout.put( stack[top--]) );       
}

int main(){
    
    IterativeReverse();
    return 0;    
}
