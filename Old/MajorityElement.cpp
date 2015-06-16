#include<iostream>

int candidate( int* arr , int size ){
    
    int maj = 0 , count = 1;
    
    for(int i = 1 ; i < size ; i++){
            
            if( arr[i] == arr[maj] )        
                count++;
            else
                count--;
            
            if( count == 0 ){
                maj = i;        
                count = 1;
            }
    }
    return arr[maj];
}

bool iscandidate( int* arr , int size , int cand ){
     
     int count = 0 ;
     for( int i = 0 ; i < size ; i++ )
          if( arr[i] == cand )
              count++;
     if( count > size/2 )
         return 1;
     
     else                  
         return 0;                  
}

int main(){
    
    int size;
    std::cin>>size;
    
    int* arr = (int*)malloc(size*sizeof(int));
    for(int i = 0 ; i < size ; i++)
            std::cin>>arr[i];
    
    int cand = candidate(arr,size);
    
    if( iscandidate(arr,size,cand))
        std::cout<<"Yes"<<cand;
    else
        std::cout<<"No Majority element";    
            
    return 0;    
}
