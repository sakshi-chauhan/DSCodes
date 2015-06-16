//http://ideone.com/1vE5y0
//Longest Increasing subsequence in O(nlgn)

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    int* a;
    cin>>n;
    
    a = new int[n];
    
    set<int> s;
    set<int>::iterator it;
    
    for(int i = 0;i < n; i++){

        cin>>a[i];
        s.insert(a[i]);
        it = s.find(a[i]);
        it++;

        if(it != s.end()){
            s.erase(it);
        }

    }
    
    cout<<s.size()<<endl;

    return 0;

}
