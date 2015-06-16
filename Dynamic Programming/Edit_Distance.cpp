//http://ideone.com/BuaiFQ
//Edit distance between two strings

#include <iostream>
#include <algorithm>
using namespace std;

int editDistance( string str1 , string str2 ){
	
	int l1 = str1.length();
	int l2 = str2.length();
	
	int d[l1+1][l2+1];
	
	
	for( int i = 0 ; i <= l1 ; i++ )
		d[i][0] = i;
		
	for( int j = 1 ; j <= l2 ; j++ )
		d[0][j] = j;
	
	for( int i = 1 ; i <= l1 ; i++ ){
		
		for( int j = 1 ; j <= l2 ; j++ ){
			
			int m = min( d[i-1][j] , d[i][j-1] )+1;
			d[i][j] = min (m , d[i-1][j-1] + (str1[i-1] == str2[j-1]?0:1));
			
		}
		
	}
	return d[l1][l2];
}

int main() {

	string str1,str2;
	cin>>str1>>str2;
	
	cout<<editDistance(str1,str2);
	
	return 0;

}
