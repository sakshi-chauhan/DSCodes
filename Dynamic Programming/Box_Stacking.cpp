//http://ideone.com/g82ReL
//Box Stacking problem in Dynamic Programming

#include <iostream>
#include <algorithm>	//for max & min

using namespace std;

struct box{
	
	int h,w,d;	
	
};

int comp( const void *a , const void *b ){
	
	return ( (*(box*)b).d * (*(box*)b).w ) - ( (*(box*)a).d * (*(box*)a).w ); 

}

int boxStackheight( box arr[] , int n ){
	
	box b[3*n];
	int in = 0;
	
	for( int i = 0 ; i < n ; i++ ){
		
		b[in] = arr[i];
		in++;
		
		b[in].h = arr[i].w;
		b[in].d = max( arr[i].h , arr[i].d );
		b[in].w = min( arr[i].h , arr[i].d );
		in++;
		
		b[in].h = arr[i].d;
		b[in].d = max( arr[i].h , arr[i].w );
		b[in].w = min( arr[i].h , arr[i].w );
		in++;
		
	}
	
	n *= 3;
	qsort( b , n , sizeof(b[0]) , comp );
	
	int h[n];
	h[0] = b[0].h;
	
	for( int i = 1 ; i < n ; i++ ){
		h[i] = b[i].h;
		for( int j = 0 ; j < i ; j++ ){
			
			if( b[i].w < b[j].w && b[i].d < b[j].d ){
				
				h[i] = max( h[i] , h[j]+b[i].h);
				
			}
		
		}
		
	}
	
	int m = -1;
	
	for( int i = 0 ; i < n ; i++ ){
		
		if( m < h[i] )
			m = h[i];
		
	}
	return m;
	
}

int main() {

	int n;
	
	cin>>n;
	
	box b[n];
	
	for( int i = 0 ; i < n ; i++ ){
	
		cin>>b[i].h>>b[i].w>>b[i].d;
	
	}
	
	cout<<boxStackheight( b , n );
	
	return 0;

}
