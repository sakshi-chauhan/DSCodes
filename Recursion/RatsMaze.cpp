//Rat's maze problem

#include<iostream>
#define N 4

bool RatsMaze( bool maze[N][N], int x , int y , bool sol[N][N] );

void printPath( bool sol[N][N] ){
     
     for( int i = 0 ; i < N ; i++ ){
          for( int j = 0 ; j < N ; j++ )
               std::cout<<sol[i][j]<<" ";
          std::cout<<"\n";     
     }
     
}

bool MoveAllowed( int x , int y , bool maze[N][N] ){
     
     if( x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 )
         return true;
     
     return false;     
}

bool solve( bool maze[N][N] ){
     
     bool sol[N][N];     
     
     for( int i = 0 ; i < N ; i++ )
          for( int j = 0 ; j < N ; j++ )
               sol[i][j] = 0;
     
     if( RatsMaze( maze,0,0,sol ) == false ){
         
         std::cout<<"Solution doesnt exist";
         return false;
             
     }               
     
     else
         printPath(sol);
         
     return true;    
}

bool RatsMaze( bool maze[N][N], int x , int y , bool sol[N][N] ){
     
     if( x == N-1 && y == N-1 ){
         
         sol[x][y] = 1;
         return true;
             
     }
     
     if( MoveAllowed(x,y,maze)){
         
         sol[x][y] = 1;    
         
         if( RatsMaze( maze, x+1 , y , sol) == true )
             return true;
         
         if( RatsMaze( maze, x , y+1 , sol) == true )
             return true;
             
         
         sol[x][y]=0;
         return false;    
             
     }
     return false;
}

int main(){
    
    bool maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    solve(maze);
    //getchar();
    return 0;
        
}
