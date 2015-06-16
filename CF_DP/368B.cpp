//http://ideone.com/G3bVks
//368B Codeforces

#include <iostream>
#include <set>

using namespace std;

int main() {

	int n,m,l;
	set<int> myset;
	set<int>::iterator it;
	
	cin>>n>>m;
	
	int* arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	for( int i = 0 ; i < m ; i++ ){
		
		cin>>l;
		if( !myset.empty() )
			myset.erase(myset.begin(),myset.end());
		
		for( int j = l-1 ; j < n ; j++ )
			myset.insert(arr[j]);
		
		cout<<myset.size()<<'\n';
	
	}	
	
	return 0;

}
