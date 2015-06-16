//http://ideone.com/8EpvKy
//Find all possible interpretations of an array of digits

#include <iostream>
using namespace std;

char alpha[27] = {"abcdefghijklmnopqrstuvwxyz"};

void printInterpretations( int* arr , char* res , int in , int i , int n ){
	
	
	if( i == n ){
		
		for( int j = 0 ; j < in ; j++ )
			cout<<res[j]<<" ";
		
		cout<<'\n';
		return;
		
	}	
	
	res[in] = alpha[ arr[i] - 1 ];
	printInterpretations( arr , res , in+1 , i+1 , n );
	
	if( i+1 != n && (arr[i]*10+arr[i+1]) < 26){
		
		res[in] = alpha[ (arr[i]*10+arr[i+1]) - 1 ];
		printInterpretations( arr , res , in+1 , i+2 , n);
	
	}
	
}

int main() {
	// your code goes here

	int n;
	
	cin>>n;
	
	int* arr = new int[n];
	char* res = new char[n];

	for(int i = 0 ; i < n ; i++)
		cin>>arr[i];

	printInterpretations(arr,res,0,0,n);

	return 0;

}
