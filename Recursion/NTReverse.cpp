//Nontail recursion - function to reverse a string

#include<iostream>

using namespace std;

void reverse(){
     
     char ch;
     cin.get(ch);
     
     if( ch != '\n' ){
         
         reverse();    
         cout.put(ch);
         
     }     
     
}

int main(){
    
    reverse();
    return 0;
        
}
