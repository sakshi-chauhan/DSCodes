//http://ideone.com/Yzm2DT
//Reverse a stack using recursion; no extra space is to be used
//Difficulty level : Thumbs Up!!

#include<iostream>
#include<stack>

using namespace std;

void printStack( stack<int> stk ){
	
	while( !stk.empty() ){
		
		cout<<stk.top()<<" ";
		stk.pop();
		
	}	
	
	std::cout<<'\n';
	
}

void insertBottom( stack<int> &stk , int data ){
	
	if( stk.empty() ){
		
		stk.push(data);
		return;
		
	}	
	else{
		
		int temp = stk.top();
		stk.pop();
		insertBottom(stk,data);
		stk.push(temp);
		
	}
}

void reverse( stack<int> &stk ){
	
	if( !stk.empty() ){
		
		int temp = stk.top();
		stk.pop();
		reverse( stk );
		insertBottom( stk ,temp );
		
	}
	
}

int main(){
	
	stack<int> stk;	
	stk.push(4);
	stk.push(2);
	stk.push(5);
	stk.push(6);
	printStack( stk );
	
	reverse( stk );
	printStack( stk );
	
	return 0;	
	
}
