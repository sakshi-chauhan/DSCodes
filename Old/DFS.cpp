#include<iostream>
#include<list>
class graph{
       
       int V;
       std::list<int>* adj;
     
       public:
              graph(int V);
              void add_edge(int a , int b);
              void DFS(int s); 
              void DFStraverse( int s , bool* V ); 
};

graph::graph( int V ){
              
      this->V = V;                      
      adj = new std::list<int> [V];
              
} 

void graph::add_edge(int a , int b){
     
     adj[a].push_back(b);     
     
}

void graph::DFS(int s){
    
    bool * visited = new bool[V];
     
    for(int i = 0 ; i < V ; i++ )      
            visited[i] = 0;
            
    DFStraverse(s,visited);         
}

void graph::DFStraverse( int s , bool * visited){
    
    visited[s] = 1;
    std::cout<<s<<" ";
    
    std::list<int>::iterator it;
    
    for( it = adj[s].begin() ; it != adj[s].end() ; it++ ){
         
         if( !visited[*it] ){
           
             DFStraverse(*it , visited);    
         }
       
    }      
     
}

int main(){
    
    graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.DFS(2);
    return 0;
        
}
