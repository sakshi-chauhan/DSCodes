#include<iostream>
#include<stack>

int main(){
    
    std::stack<int> S;
    S.push(2);
    S.push(3);
    std::cout<<S.top();
    
    return 0;    
    
}
