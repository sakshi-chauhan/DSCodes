#include<iostream>
#include<list>

class graph{
       
       int V;
       std::list<int>* adj;
     
       public:
              graph(int V);
              void add_edge(int a , int b);
              void BFS(int s);  
};

graph::graph( int V ){
              
      this->V = V;                      
      adj = new std::list<int> [V];
              
} 

void graph::add_edge(int a , int b){
     
     adj[a].push_back(b);     
     
}

void graph::BFS( int s ){
     
    bool *visited = new bool[V];
    
    for( int i = 0 ; i < V ; i++ )
         visited[i] = 0;
         
    std::list<int> q;
    
    visited[s] = 1;
    q.push_back(s);
    
    std::list<int>::iterator i;
    
    while( !q.empty() ){
        
        int o = q.front();
        std::cout<<o<<" ";
        q.pop_front();
            
        for( i = adj[o].begin() ; i != adj[o].end() ; i++ ){
             
           
             if( !visited[*i] ){
                     
                 visited[*i] = 1;
                 q.push_back(*i);
                 
             }
                  
        }   
           
    }      
}

int main(){
    
    //int V;
    //std::cin>>V;
    
    /*graph g(8);
    g.add_edge(1,2);
    g.add_edge(1,4);
    g.add_edge(2,3);
    g.add_edge(3,5);
    g.add_edge(3,6);
    g.add_edge(5,6);
    g.add_edge(5,7);
    g.add_edge(6,7);
    g.add_edge(6,8);
    g.add_edge(7,8);*/
    
    
    graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.BFS(2);
        
    return 0;
        
}

