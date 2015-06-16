//http://ideone.com/YYH9qG
//Find the next greater element of each element of the array
//Difficulty level : Cute

#include<iostream>
#include<stack>

using namespace std;

int main(){
	
	int n,i,top;
	int* arr;
	
	cin>>n;
	arr = new int[n];
	
	for( i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	stack<int> stk;
	
	stk.push( arr[0] );
	
	for( i = 1 ; i < n ; i++ ){
		
		if( !stk.empty() ){
		
			top = stk.top();
		
			if( top < arr[i] ){
				
				while( top < arr[i] ){
					
					cout<<top<<"  NGE = "<<arr[i]<<"\n";
					stk.pop();
					
					if( stk.empty() )
						break;
					
					top = stk.top();
						
				}
				
			}
			
		}
		
		stk.push(arr[i]);
	
	}
	
	while( !stk.empty() ){
		
		cout<<stk.top()<<"  NGE = -1\n";
		stk.pop();
		
	}
	
	return 0;
	
}
