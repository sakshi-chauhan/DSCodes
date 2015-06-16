#include <iostream>
#include <map>

using namespace std;

int main() {
	
	char a , b;
	map<char , char> emp_mgr;
	map<char , int > mgr_emp;
	
	int n;
	cin>>n;
	
	for( int i = 0 ; i < n ; i++ ){
		
		cin>>a>>b;
		emp_mgr.insert( pair<char,char>(a,b) );
		
	}
	
	map<char,char>::iterator it1;
	map<char,int>::iterator it2;
	
	for( it1 = emp_mgr.begin() ; it1 != emp_mgr.end() ; it1++ ){
		
		if( it1 -> first != it1 -> second ){
			
			//char ch = it1->second;
			
			if( mgr_emp.find(it1->second) != mgr_emp.end() ){
				
				mgr_emp.find(it1->second)->second++;
				
			}
			else
				mgr_emp.insert( pair<char,int >(it1->second,1));
			
		}
		
	}
	
	for( it1 = emp_mgr.begin() ; it1 != emp_mgr.end() ; it1++ ){
		
		if( mgr_emp.find(it1->first) != mgr_emp.end() && it1 -> first != it1 -> second ){
			
			mgr_emp.find( it1->second )->second += mgr_emp.find(it1->first)->second;
			
		}
		else
			mgr_emp.insert( pair<char,int> (it1->first,0));
	}
	
	for( it2 = mgr_emp.begin() ; it2 != mgr_emp.end() ; it2++ )
		cout<<it2->first<<" "<<it2->second<<'\n';
	
	return 0;

}
