//http://ideone.com/lLFizh
//Program to rotate an array

#include <iostream>
using namespace std;

void print_array( int *arr , int n ){
	
	for( int i = 0 ; i < n ; i++ )
		cout<<arr[i]<<" ";
	cout<<'\n';
	
}

int gcd( int a , int b ){
	
	if( b > a )
		return gcd(b,a);
	if( b == 0 )
		return a;
	
	return gcd(b,a%b);	
	
}

void leftRotate(int arr[], int n, int d ){
	
  int i, j, k, temp;
  for (i = 0; i < gcd(d, n); i++){
    
    temp = arr[i];
    j = i;
    
    while(1){
    
	      k = j + d;
	      if (k >= n)
	        k = k - n;
	      if (k == i)
	        break;
	      arr[j] = arr[k];
	      j = k;
    
    }
    
    arr[j] = temp;
  }
}

int main() {

	int n,d;
	cin>>n>>d;
	
	int *arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	print_array(arr,n);
	//cout<<rotateArray(arr,n,d);
	//cout<<gcd(12,3);
	
	leftRotate( arr , n , d );
	print_array(arr,n);

	return 0;

}
