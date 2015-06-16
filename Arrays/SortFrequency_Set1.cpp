//https://ideone.com/FMPqpY

#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp;//stores the count of elements
unordered_map<int,int>mp1;// stores the smallest index where element has occurred
//int a[] = {2,5,2,8,5,6,8,8};
int a[] = {5,2,2,8,5,6,8,8};
bool aso(int x,int y)
{
    if(mp[a[x]]!=mp[a[y]])
    	return (mp[a[x]]>mp[a[y]]);
    else 
    	return (mp1[a[x]]<mp1[a[y]]);
}
int main()
{
    int b[100],i,j,n=8;
    b[0] = 0;
    mp[a[0]]++;
    mp1[a[0]] = 0;
    
    for(i=1;i<n;i++)
    {
        b[i]=i;
        mp[a[i]]++;
        
        if( mp1[a[i]] == 0 && a[i] != a[0] ){
        	mp1[a[i]]=i;
        	//cout<<"mp1["<<a[i]<<" = "<<i<<'\n';
        }
    }
    sort(b,b+n,aso);
    for(i=0;i<n;i++)
        cout<<a[b[i]]<<" ";
    return 0;
}
