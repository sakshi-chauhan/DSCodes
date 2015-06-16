//Simpe iterative reverse using strlen and getline built in functions

#include<iostream>

using namespace std;

void SimpleIterativeReverse(){
     
     char stack[80];
     int top = 0;
     
     cin.getline(stack,80);
     
     for(top = strlen(stack)-1 ; top >= 0 ; cout.put(stack[top--]) );
     
}

int main(){
    
    SimpleIterativeReverse();
    return 0;
        
}
