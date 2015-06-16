#include<iostream>
#include<vector>

struct Edge{
       
       int src;
       int dest;     
       
};

struct Graph{
       
       int V;
       int E;     
       struct Edge* edge;   //to store the edge list
       
};

struct Graph* create(int V , int E){
       
       struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
       graph->E = E;
       graph->V = V;
       
       graph->edge = (struct Edge*)malloc(E*sizeof(struct Edge));
       
       return graph;
}

void makeset( struct Graph* g , int V ,std::vector<int> set[]){
     
     for(int i = 0 ; i < V ; i++ )
             set[i].push_back(i+1);
     
     //for( int i = 0 ; i < V ; i++ )
         //std::cout<<set[i].size()<<"\n";
          
}

int findset(int V, std::vector<int> set[] ,int v1){

     for(int i = 0 ; i < V ; i++ ){
             
            for(int j = 0 ; j < set[i].size() ; j++ ){
                    
                    if( set[i][j] == v1 )
                        return set[i][0];       
            } 
                     
     }
}

void union(int V,std::vector<int> set[],int v1 , int v2){
     
     if( findset(V,set,v1) != findset(V,set,v2) ){
     
         int a = findset(V,set,v1);    
         int b = findset(V,set,v2);
         
     }     
     
}

int main(){
    
    int V,E;
    struct Graph* g;
    
    std::cout<<"Enter number of edges: ";
    std::cin>>E;
    
    std::cout<<"Enter number of vertices: ";
    std::cin>>V;
    
    g = create(V,E);
    std::cout<<"Enter the edges:\n";
    
    for(int i = 0 ; i < E ; i++){
            
            std::cout<<"Source : ";
            std::cin>>g->edge[i].src;
            
            std::cout<<"Destination : ";
            std::cin>>g->edge[i].dest;        
            
    }
    std::vector<int> set[V];
    makeset(g,V,set);
    
    
    //std::cout<<findset(V,set,1)<<"\n";
    //std::cout<<findset(V,set,2)<<"\n";
    return 0;    
}
