//http://ideone.com/TMG12h
//Counting Boolean parenthesizations

#include <iostream>
using namespace std;

int booleanParen( char* sym , char * opr , int n ){

	int T[n][n],F[n][n];
	
	for( int i = 0 ; i < n ; i++ ){
		
		T[i][i] = (sym[i]=='T')?1:0;
		F[i][i] = (sym[i]=='F')?1:0;
		
	}
	
	for( int gap = 1 ; gap < n ; gap ++ ){
		
		for( int i = 0 , j = gap ; j < n ; i++,j++ ){
			
			T[i][j] = F[i][j] = 0;
			
			for( int k = i ; k < j ; k++ ){
				
				int tik = T[i][k] + F[i][k];
				int tkj = T[k+1][j] + F[k+1][j];
				
				if( opr[k] == '&' ){
					
					T[i][j] += T[i][k]*T[k+1][j];
					F[i][j] += (tik*tkj - T[i][k]*T[k+1][j]);
					
				}
				if( opr[k] == '|' ){
					
					F[i][j] += F[i][k]*F[k+1][j];
					T[i][j] += (tik*tkj - F[i][k]*F[k+1][j]);
					
				}
				if( opr[k] == '^' ){
					
					T[i][j] += T[i][k]*F[k+1][j] + T[k+1][j]*F[i][k];
					F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
					
				}
				
			}
			
		}
		
	}
	
	return T[0][n-1];
	
}

int main() {

	int n;
	cin>>n;
	
	char* sym = new char[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>sym[i];
	
	char* opr = new char[n-1];
	
	for( int i = 0 ; i < n-1 ; i++ )
		cin>>opr[i];
	
	cout<<booleanParen( sym , opr , n );	
	
	return 0;

}
