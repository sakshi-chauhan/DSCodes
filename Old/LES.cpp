//Even length substring whose left and right have equal sum

#include<iostream>

int LES(std::string str){
    
    int n = str.length();
    int maxlen = 0;
    int left,right,len;
    
    //starting of substring
    for( int i = 0 ; i < n-1 ; i++ ){
         //ending of substring
         for( int j = i+1 ; j < n ; j += 2 ){
              
                 len = j - i + 1; //length of substring 
                 left = right = 0;
                 
                 for( int k = 0 ; k < len/2 ; k++ ){
                      
                      left += str[i+k] - '0';
                      right += str[i+k+len/2] - '0';     
                      
                 } 
                 
                 if( left == right && maxlen < len )
                     maxlen = len;
         }     
         
    }
    
    return maxlen;
    
}

int main(){
    
    std::string str;
    std::cin>>str;
    
    std::cout<<LES(str);
    return 0;
        
}
