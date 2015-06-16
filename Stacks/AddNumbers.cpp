//http://ideone.com/kneolB
//Add two numbers using stacks

#include <iostream>
#include<stack>

int reverseNumber( int num ){
	
	int rev = 0;
	
	while( num > 0 ){
		
		rev = ( rev * 10 ) + ( num % 10 ) ;
		num /= 10;
		
	}
	
	return rev;
	
}

void printStack( std::stack<int> s ){
	
	while( !s.empty() ){
		
		std::cout<<s.top();
		s.pop();
	
	}
	
	std::cout<<'\n';

}

int main() {
	// your code goes here
	
	std::stack<int> stk1;
	std::stack<int> stk2;
	std::stack<int> res;
	
	int num1,num2;
	int rev1,rev2;
	
	std::cin>>num1>>num2;
	
	rev1 = reverseNumber( num1 );
	rev2 = reverseNumber( num2 );
	
	//std::cout<<rev1<<"  "<<rev2;	
	
	while( rev1 > 0 ){
		
		stk1.push( rev1%10 );
		//std::cout<<stk1.top()<<" ";
		rev1 /= 10;
		
	}
	
	while( rev2 > 0 ){
		
		stk2.push( rev2%10 );
		//std::cout<<stk2.top()<<" ";
		rev2 /= 10;
		
	}
	
	int sum,carry=0;
	
	while( !stk1.empty() && !stk2.empty() ){
		
		sum = stk1.top() + stk2.top() + carry;
		//std::cout<<sum;
		
		if( sum >= 10 ){
			
			sum %= 10;
			carry = 1;
			
		}
		else
			carry = 0;
			
		res.push(sum);
		//std::cout<<res.top()<<" ";
		stk1.pop();
		stk2.pop();
		
	}
	
	//printStack( res );
	
	if( !stk1.empty() ){
		
		while( !stk1.empty() ){
			
			if( carry ){
				
				sum = stk1.top() + 1;
				res.push( sum );
				stk1.pop();
				carry = 0;
				
			}
			
			else{
				
				res.push( stk1.top() );
				stk1.pop();
				
			}
		
		}
		
	}
	
	else if( !stk2.empty() ){
		
		while( !stk2.empty() ){
			
			if( carry ){
				
				sum = stk2.top() + 1;
				res.push( sum );
				stk2.pop();
				carry = 0;
				
			}
			
			else{
				
				res.push( stk2.top() );
				stk2.pop();
				
			}
		
		}
		
	}
	
	printStack( res );
	return 0;

}
