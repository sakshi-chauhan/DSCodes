//http://ideone.com/8v0pYm
//489C Codeforces

#include <iostream>
#include <algorithm>

using namespace std;

bool can( int m , int s ){
	
	return s >= 0 && s <= 9*m;
	
}

bool comp( char a , char b ){
	
	return a>b;
	
}

int main() {

	int m , s;
	bool flag = 0;
	string min = "";
	
	cin>>m>>s;
	
	for( int i = 0 ; i < m  ; i++ ){
		
		for( int d = 0 ; d < 10 ; d++ ){
			
			if( (i > 0 || d > 0 || (m == 1 && d == 0 ) ) && can( m-i-1 , s - d ) ){
				
				min += char( '0' + d );
				s -= d;
				flag = 1;
				break;
				
			}
			
		}
	}

	if( flag ){

		cout<<min<<" ";
		sort( min.begin() , min.end() , comp );
		cout<<min;
	
	}
	else
		cout<<"-1 -1";
	return 0;

}
