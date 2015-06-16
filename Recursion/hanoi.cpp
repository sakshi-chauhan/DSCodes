//Towers of Hanoi problem
#include<iostream>

using namespace std;

void TowersOfHanoi( int n_disk, char from , char aux , char to ){ //say, from A to C using B
     
     if( n_disk == 1 ){
         
         cout<<"Transfer disk 1 from "<<from<<" to "<<to<<"\n";
         return; 
             
     }
     
     //transer n-1 disks from A to B
     TowersOfHanoi( n_disk-1 , from , to , aux );
     
     //remaining from A to C 
     cout<<"Transfer disk "<<n_disk<<" from "<<from<<" to "<<to<<"\n";
     
     //transfer n-1 disks from B to C 
     TowersOfHanoi( n_disk-1 , aux , from , to );
}

int main(){
     
     int num_disk;
     
     cout<<"Enter the number of disks : ";
     cin>>num_disk;
     
     TowersOfHanoi( num_disk, 'A' , 'B' , 'C' );
     
     return 0;
          
}
