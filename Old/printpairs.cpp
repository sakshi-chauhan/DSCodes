#include<iostream>
#include<cstdio>
#include<cstring>

int main(){
    
    int n,sum;
    
    std::cin>>n;
    
    int* arr = (int*)malloc(sizeof(int)*n);
    
    for( int i = 0 ; i < n ; i++ )
         std::cin>>arr[i];
    
    std::cin>>sum;
    
    bool* map = (bool*)malloc(sizeof(bool)*n);     
    memset(map,0,sizeof(map));
    
    for(int i = 0 ; i < n ; i++ ){
            
            if( map[sum-arr[i]] == 1 ){
                
                std::cout<<arr[i]<<"  "<<sum-arr[i]<<"\n";
                    
            }        
            map[arr[i]] = 1;
    }
    
    return 0;    
    
}
