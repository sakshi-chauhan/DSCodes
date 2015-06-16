//Knight's tour problem

#include<iostream>
#define N 8

bool KnightsTour(int x, int y, int movei, int sol[N][N], int xMove[N],int yMove[N]);

void printTour( int sol[N][N] ){
     
     for( int i = 0 ; i < N ; i++ ){
          for( int j = 0 ; j < N ; j++ )
               std::cout<<sol[i][j]<<" ";
          std::cout<<"\n";     
     }
}

bool MoveAllowed( int x , int y , int sol[N][N] ){
     
     if( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1 )
         return true;
     
     return false;     
}

bool solve(){
     
     int sol[N][N];
     
     for( int i = 0 ; i < N ; i++ )
          for( int j = 0 ; j < N ; j++ )     
               sol[i][j] = -1;
               
     int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
     int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
 
    // Since the Knight is initially at the first block
    sol[0][0]  = 0;
 
    /* Start from 0,0 and explore all tours using solveKTUtil() */
    if(KnightsTour(0, 0, 1, sol, xMove, yMove) == false){
        std::cout<<"Solution does not exist";
        return false;
    }
    else
        printTour(sol);
 
    return true;   

}

bool KnightsTour(int x, int y, int movei, int sol[N][N], int xMove[N],int yMove[N]){
     
     int k, next_x, next_y;
     if (movei == N*N)
       return true;
 
   /* Try all next moves from the current coordinate x, y */
     for (k = 0; k < 8; k++){
       
       next_x = x + xMove[k];
       next_y = y + yMove[k];
       if (MoveAllowed(next_x, next_y, sol)){
         sol[next_x][next_y] = movei;
         
         if ( KnightsTour(next_x, next_y, movei+1, sol, xMove, yMove) == true)
             return true;
         else
             sol[next_x][next_y] = -1;// backtracking
       
       }
   }
 
   return false;     
     
}

int main(){
    
    solve();
    return 0;
        
}
