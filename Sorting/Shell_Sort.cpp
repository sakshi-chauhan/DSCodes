//http://ideone.com/Auy3JJ
//Implementation of Shell sort

#include <iostream>
using namespace std;

void print_array( int* arr , int size ){
 
	for( int i = 0 ; i < size ; i++ )
		cout<<arr[i]<<" ";
	cout<<'\n';
 
}
 
void ShellSort( int* arr , int n ){
	
	int i,j,k,h,hCnt;
	int increments[20];
	
	for( h = 1 , i = 0 ; h < n ; i++ ){
		
		increments[i] = h;
		h = 3*h + 1;
		
	}
	
	for( i-- ; i >= 0 ; i-- ){
		
		h = increments[i];
		
		for( hCnt = h ; hCnt < 2*h ; hCnt++ ){
			
			for( j = hCnt ; j < n ; ){
				
				int temp = arr[j];
				k = j;
				while( k - h >= 0 && temp < arr[k-h] ){
					
					arr[k] = arr[k-h];
					k -= h;
					
				}
				arr[k] = temp;
				j += h;
				
			}
			
		}
		
	}
} 

int main() {
	
	int n;
	int* arr;
	
	cin>>n;
	arr = new int[n];
	
	for( int i = 0 ; i <n ; i ++ )
		cin>>arr[i];
	
	ShellSort(arr,n);
	print_array(arr,n);
		
	return 0;

}
