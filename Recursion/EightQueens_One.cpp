// 8 queens problem

#include<iostream>

class chessboard{
      
      public:
             chessboard();    
             chessboard( int );
             void FindSolution();
      private:
             const bool available;
             const int square,norm;
             bool *column, *leftdiagonal , *rightdiagonal;
             int *positionInRow , howMany;       
             void putQueen( int );
             void initialiseBoard();
             void printBoard();
};

chessboard::chessboard(): available(true) , square(8) , norm( square-1 ){
                         
       initialiseBoard();
                                                  
}

chessboard::chessboard( int n ) : available(true) , square(n) , norm( square-1 ){
                         
       initialiseBoard();
                                                  
}

void chessboard::initialiseBoard(){

       int i;
       column = new bool[square];
       leftdiagonal = new bool[ 2*square - 1 ];
       rightdiagonal = new bool[ 2*square - 1 ];  
       
       for( i = 0 ; i < square ; i++ ){
            positionInRow[i] = -1;
            column[i] = available;
       }
       
       for( i = 0 ; i < 2*square-1 ; i++ )                           
            leftdiagonal[i] = rightdiagonal[i] = available;
       
       howMany = 0;       
}

void chessboard::putQueen( int row ){

     for( int col = 0 ; col < square ; col++ )
     
          if( column[col] == available && leftdiagonal[row+col] == available && rightdiagonal[row-col+norm] == available ){
              
              positionInRow[row] = col;
              column[col] = !available;    
              leftdiagonal[row+col] = !available; 
              rightdiagonal[row-col+norm] = !available;
              
              if( row < square - 1 )
                  putQueen( row+1 );
              else{
                  printBoard();
                  break;
                  //howMany++;
              }
                  
              column[col] = available;    
              leftdiagonal[row+col] = available; 
              rightdiagonal[row-col+norm] = available;    
          }     
     
}

void chessboard::FindSolution(){
     
     putQueen(0);
     //std::cout<<howMany<<" solutions found\n";     
     
}

void chessboard::printBoard(){
     
     for( int i = 0 ; i < square ; i++ ){
          
          for( int j = 0 ; j < square ; j++ ){
               
               if( positionInRow[i] != j )
                   std::cout<<" - ";     
               else
                   std::cout<<" Q ";
          }     
          std::cout<<'\n';
     }     
     
}

int main(){
    
    chessboard c;
    c.FindSolution();
    return 0;
        
}
