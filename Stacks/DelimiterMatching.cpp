//http://ideone.com/trNXSf
//Delimiter matching using stacks

#include<iostream>
#include<stack>

bool isOperator( char op ){
	
	return ( op=='+' ) || ( op == '-') || ( op == '*') || ( op == '/' );	
	
}

bool isChar( char ch ){
	
	return (ch >= 'a' && ch <= 'z') || ( ch >= 'A' && ch <= 'Z' );
	
}

bool delimiterMatch( std::stack<char> stk , std::string str ){
	
	int i = 0;
	char ch,el;
	
	while( str[i] ){
		
		ch = str[i];
		
		if( (ch == '(') || (ch == '{') || (ch == '[') )	
			stk.push(ch);
		
		else if( (ch == ')') || (ch == '}') || (ch == ']') ){
			
			el = stk.top();
			stk.pop();
			
			if ( ch == ')' ){
				
				if( el != '(' )
					return 0;
				
			}
			
			else if ( ch == '}' ){
				
				if( el != '{' )
					return 0;
				
			}
			
			else if ( ch == ']' ){
				
				if( el != '[' )
					return 0;
				
			}
		}
		
		i++;
	}
	
	if( stk.empty() )
		return 1;
	else
		return 0;
	
}

int main(){
	
	std::stack<char> s;
	
	std::string str;
	
	std::cin>>str;
	
	if( delimiterMatch(s,str) )
		std::cout<<"Expression is well formed!!";
	else
		std::cout<<"Ill formed expression";
	return 0;
	
}
