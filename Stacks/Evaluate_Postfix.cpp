//http://ideone.com/I77fu5
//Evaluation of postfix expression using stacks

#include <iostream>
#include<cctype>
#include<stack>


int main(){
	
	std::string exp;
	std::stack<int> stk;
	int i = 0;
	int op1,op2,res;
	
	std::cin>>exp;
	
	while( exp[i] ){
			
		if( isdigit(exp[i]) ){
			
			stk.push( exp[i] - '0' );
			//std::cout<<exp[i]<<" ";
			//std::cout<<stk.top()<<"pushed onto the stack\n";
			
		}
		
		else{
			
			op2 = stk.top();
			stk.pop();
			op1 = stk.top();
			stk.pop();
			
			
			switch( exp[i] ){
				
				case '+' :  stk.push( op1 + op2 );
							//std::cout<<stk.top()<<"pushed onto the stack\n";
							break;
				case '-' :  stk.push( op1 - op2 );
							//std::cout<<stk.top()<<"pushed onto the stack\n";
							break;
				case '*' :  stk.push( op1 * op2 );
							//std::cout<<stk.top()<<"pushed onto the stack\n";
							break;
				case '/' :  stk.push( op1 / op2 );
							//std::cout<<stk.top()<<"pushed onto the stack\n";
							break;
							
			}				
		}
		
		i++;
		
	}
	
	std::cout<<stk.top();
	
	return 0;	
	
}
