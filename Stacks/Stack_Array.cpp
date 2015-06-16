//http://ideone.com/UXHNaZ
//Implementing stacks as arrays
#include <iostream>
#define SIZE 10

class stack{
	
	int arr[ SIZE ];
	int top;
	
	public:
	
	stack(){
		
		top = -1;
		
	}

	bool isFull(){
		
		return top == SIZE-1;
		
	}
	
	bool isEmpty(){
		
		return top == -1;
		
	}
	
	void push( int el );
	int pop();
	
};

void stack::push( int el ){
	
	if( isFull() ){
		
		std::cout<<"No space in the stack!!\n";
		return;
		
	}

	arr[ ++top ] = el;
	std::cout<<el<<" pushed on to the stack!!\n";
	
}

int stack::pop(){
	
	if( isEmpty() ){
		
		std::cout<<"Stack is empty, cannot delete any further!!\n";
		return -1;
	}
	
	int el = arr[top];
	top--;
	
	return el;
}

int main() {

	// your code goes here

	stack stk;
	//stk.pop();
	stk.push(23);
	stk.push(2);
	stk.push(45);
	stk.push(13);
	stk.push(98);
	stk.push(56);
	stk.push(71);
	stk.push(80);
	stk.push(65);
	stk.push(1);
	
	std::cout<<stk.pop()<<" deleted\n";
	stk.push(21);
	
	return 0;

}
