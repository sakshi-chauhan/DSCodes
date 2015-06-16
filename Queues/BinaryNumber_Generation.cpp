//http://ideone.com/46ATNY
//Generate all binary numbers from 1 - n using queues
//Difficulty level : <Yawn>

#include <iostream>
#include<queue>

using namespace std;

void generateBinary( int n ){
	
	queue<string> q;
	string s1,s2;
	q.push("1");
	
	while( n-- ){
		
		s1 = q.front();
		s2 = s1;
		
		cout<<s1<<"\n";
		q.pop();
		
		q.push(s1.append("0"));
		q.push(s2.append("1"));
	}
	
	
}

int main() {
	// your code goes here
	
	int n;
	cin>>n;

	generateBinary( n );

	return 0;

}
