//http://ideone.com/nmr5X7
//368B using dp not stl

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	
	int n,m,l,i,j;
	cin>>n>>m;
	
	int* arr = new int[n];
	int* dp = new int[n];
	bool disc[100005];
	memset(dp,0,sizeof(dp));
	memset(disc,0,sizeof(disc));
	
	
	for( i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	//dp[i] denotes the number of disctinct numbers in the array from i..n-1	
	dp[n-1] = 1;	
	disc[arr[n-1]] = 1;
	
	for( i = 0 ; i < m ; i++ ){
		
		cin>>l;
		
		for( j = n-2 ; j >= l-1 && j >= 0 ; j-- ){
			
			dp[j] = dp[j+1];//
			
			if( !disc[arr[j]] ){
				dp[j] += 1;
				disc[arr[j]] = 1;
			}
			//cout<<"dp["<<j<<"] = "<<dp[j];
		}
		
		cout<<dp[j+1]<<'\n';
		memset(dp,0,sizeof(dp));
		memset(disc,false,sizeof(disc));
		
	}	
	
	return 0;

}
