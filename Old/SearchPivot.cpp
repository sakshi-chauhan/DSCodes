#include<iostream>

int findPivot( int* arr , int low ,  int high ){
   if( low > high )
        return -1;
   if( low == high )    
        return low; 
   int mid = (low + high)/2;   
   
   if (mid < high && arr[mid] > arr[mid + 1])
     return mid;
     
   if (mid > low && arr[mid] < arr[mid - 1])
     return (mid-1);
     
   if (arr[low] >= arr[mid])
     return findPivot(arr, low, mid-1);
     
   else
     return findPivot(arr, mid + 1, high);
}


int BinarySearch(int* arr , int low , int high , int ele){
    
    int mid;
    
    if( low > high )
        return -1;
    
    mid = ( low + high )/2;    
    
    if( arr[mid] == ele )
        return mid+1;
    
    if( arr[mid] < ele )
        return BinarySearch(arr,mid+1,high,ele);
    
    else        
        return BinarySearch(arr,low,mid-1,ele);        
        
}



int pivotedBinarySearch(int* arr, int size, int ele){
   
   int pivot = findPivot(arr, 0, size-1);
 
   if (pivot == -1)
     return BinarySearch(arr, 0, size-1, ele);
 
  
   if (arr[pivot] == ele)
     return pivot;
     
   if ( arr[0] <= ele )
     return BinarySearch(arr, 0, pivot-1, ele);
     
   else
     return BinarySearch(arr, pivot+1, size-1, ele);
}
 
int main(){
    
    int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int arr_size = sizeof(arr1)/sizeof(arr1[0]);
    int no = 3;
    std::cout<<pivotedBinarySearch(arr1, arr_size, no);
    
    return 0;    
}
