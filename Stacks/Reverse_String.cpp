//http://ideone.com/xGY7zK
//Reverse a string using a stack
//Difficulty level : Meh

#include<iostream>
#include<stack>

int main(){
	
	std::string str;
	std::stack<char> stk;
	int i = 0;
	
	std::cin>>str;
	
	while( str[i] ){
		
		stk.push( str[i] );
		//std::cout<<stk.top()<<" ";
		i++;
		
	}
	
	i = 0;
	
	while( !stk.empty() ){
		
		str[i] = stk.top();
		stk.pop();
		i++;
		
	}
	
	std::cout<<str;
	return 0;
	
}
