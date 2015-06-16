//http://ideone.com/Nc6bEW
//BFS in a graph

#include <iostream>
#include <list>
using namespace std;

class graph{
	
	int V;
	list<int> *adj;
	
	public:
		graph( int V );
		void add_edge( int src , int dest );
		void BFS( int s );
	
};

graph::graph( int ver ){
	
	V = ver;
	adj = new list<int>[V];
	
}

void graph::add_edge( int src , int dest ){
	
	adj[src].push_back(dest);
	
}

void graph::BFS( int src ){
	
	bool visited[V];
	
	for( int i = 0 ; i < V ; i++ )
		visited[i] = false;
	
	list<int> l;
	visited[src] = true;
	l.push_back(src);
	
	list<int>::iterator it;
	
	while( !l.empty() ){
		
		int s = l.front();
		cout<<s<<" ";
		l.pop_front();
		
		for( it = adj[s].begin() ; it != adj[s].end() ; it++ ){
			
			if( !visited[*it] ){
				
				visited[*it] = true;
				l.push_back(*it);
			
			}
		}
		
	}
	
}
int main() {
	
	int V,E,s,d;
	
	cin>>V>>E;
	
	graph g(V);
	
	for( int i = 0 ; i < E ; i++ ){
		
		cin>>s>>d;
		g.add_edge(s,d);
		
	}
	
	g.BFS(0);

	return 0;

}
