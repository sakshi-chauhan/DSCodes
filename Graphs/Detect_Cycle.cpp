//http://ideone.com/unk5eT
//Detect presence of a cycle in a graph

#include <iostream>
#include <list>
using namespace std;

class graph{
	
	int V;
	list<int> *adj;
	
	public:
		graph( int ver );
		void add_edge( int src , int dest );
		bool isCyclic( int , bool* , bool* );
		bool detect();
};

graph::graph( int ver ){
	
	V = ver;
	adj = new list<int>[V];
	
}

void graph::add_edge( int src , int dest ){
	
	adj[src].push_back(dest);
	
}

bool graph::isCyclic( int s , bool* visited , bool* stack ){
	
	if( !visited[s] ){
		
		visited[s] = true;
		stack[s] = true;
	
		list<int>::iterator it;
		
		for( it = adj[s].begin() ; it != adj[s].end() ; it++ ){
			
			if( !visited[*it] && isCyclic(*it , visited, stack ))
				return true;
				
			else if( stack[*it] )
				return true;
		}
		
	}
	
	stack[s] = false;
	return false;
}

bool graph::detect(){
	
	bool visited[V]; 
	bool stack[V]; 
	
	for( int i = 0 ; i < V ; i++ )
		visited[i] = stack[i] = false;
	
	for( int i = 0 ; i < V ; i++ )
		if( isCyclic( i , visited , stack ))
			return true;
	
	return false;		
}

int main() {
	
	int V,E,s,d;
	
	cin>>V>>E;
	
	graph g(V);
	
	for( int i = 0 ; i < E ; i++ ){
		
		cin>>s>>d;
		g.add_edge(s,d);
		
	}
	
	if( g.detect() )
		cout<<"Graph has a cycle.\n";
	else
		cout<<"Graph is acyclic.\n";
	
	return 0;

}
