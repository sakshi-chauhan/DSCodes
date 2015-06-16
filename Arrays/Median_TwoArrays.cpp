//http://ideone.com/pZHeQn
//Find median of two sorted arrays

#include <iostream>
#include <algorithm>

using namespace std;

/*int max( int a , int b ){
	
	return a>b?a:b;	
	
}

int min( int a , int b ){
	
	return a<b?a:b;
	
}*/

int median( int* arr , int n ){
	
	if( n%2 )
		return arr[n/2];
	else	
		return (arr[n/2]+arr[n/2-1])/2;
		
} 

int getMedian( int* arr1 , int* arr2 , int n ){
	
	if( n <= 0 )	
		return -1;
	
	if( n == 1 )
		return ( arr1[0]+arr2[0] )/2;
	
	if( n == 2 )
		return ( max(arr1[0],arr2[0]) + min(arr1[1],arr2[1]) )/2;
		
		
	int m1 = median( arr1 , n );
	int m2 = median( arr2 , n );
	
	if( m1 < m2 ){
		
        if (n % 2 == 0)
            return getMedian(arr1 + n/2 - 1, arr2, n - n/2 +1);
        
        else
            return getMedian(arr1 + n/2, arr2, n - n/2);
    
    }
 
    /* if m1 > m2 then median must exist in ar1[....m1] and ar2[m2...] */
    else{
        
        if (n % 2 == 0)
            return getMedian(arr2 + n/2 - 1, arr1, n - n/2 + 1);
    
        else
            return getMedian(arr2 + n/2, arr1, n - n/2);
    
    }

}

int main() {
	
	int n;
	cin>>n;
	
	int *arr1,*arr2;
	
	arr1 = new int[n];
	arr2 = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr1[i];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr2[i];	

	cout<<getMedian(arr1,arr2,n);

	return 0;

}
