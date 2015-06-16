//http://ideone.com/Yer5FM
//The stock span problem
//Difficulty level : Jugaad

#include<iostream>
#include<stack>

using namespace std;

void printArray( int *arr , int n ){
	
	for( int i = 0 ; i < n ; i++ )
		cout<<arr[i]<<" ";
	
	cout<<"\n";
	
}

void calc_span( int *p , int n , int *s ){
	
	stack<int> stk;
	
	stk.push(0);
	s[0] = 1;
	
	for( int i = 1 ; i < n ; i++ ){
	
		while( (!stk.empty()) && ( p[stk.top()] < p[i] ) )
			stk.pop();
			
		s[i] = (stk.empty())? (i+1) : ( i - stk.top() );
		
		stk.push(i);
	}
}

int main(){
	
	int n;
	int *price;
	int *span;
	cin>>n;
	
	price = new int[n];
	span = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>price[i];
		
	calc_span( price , n , span );
	
	printArray( span , n );
		
	return 0;
	
}
