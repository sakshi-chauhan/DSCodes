//http://ideone.com/J1TQDR
//Longest path in a DAG

#include <iostream>
#include <list>
#include <stack>
#include <climits>

#define MIN INT_MIN

using namespace std;

struct node{
	
	int d;
	int wt;
	
};

class graph{
	
	int V;
	list<node>* adj;
	
	public:
		graph( int V );
		void Topological_Sort( int , bool* , stack<int>& );
		void longestPath( int s );
		void add_edge( int s , int d , int w );		
};

graph::graph( int ver ){
	
	V = ver;
	adj = new list<node>[V];
	
}

void graph::add_edge( int s , int d , int w ){
	
	node nn;
	nn.d = d;
	nn.wt = w;
	
	adj[s].push_back(nn);
	
}

void graph::Topological_Sort( int v , bool* visited , stack<int>& stk ){
	
	visited[v] = true;
	
	list<node>::iterator it;
	
	for( it = adj[v].begin() ; it != adj[v].end() ; it++ ){
		
		if( !visited[(*it).d] )
			Topological_Sort( (*it).d, visited , stk );
		
	}
	//cout<<v<<" pushed into stack.\n";
	stk.push(v);

}

void graph::longestPath( int s ){
	
	bool* visited = new bool[V];
	stack<int> stk;
	
	for( int i = 0 ; i < V ; i++ )
		visited[i] = false;
	
	for( int i = 0 ; i < V ; i++ )
		if( !visited[i] )
			Topological_Sort( i , visited , stk );
	
	int dist[V];
	
	for( int i = 0 ; i < V ; i++ )
		dist[i] = MIN;
	
	dist[s] = 0;
	
	while( !stk.empty() ){
		
		int u = stk.top();
		stk.pop();
		
		list<node>::iterator it;
		
		if( dist[u] != MIN ){
		
				for( it = adj[u].begin() ; it != adj[u].end() ; it++ )
					
					if( dist[(*it).d] < dist[u] + (*it).wt )
						dist[(*it).d] = dist[u] + (*it).wt;
		}	
	}
	
	for( int i = 0 ; i < V ; i++ ){
		if( dist[i] == MIN )
			cout<<"-INF ";
		else
			cout<<dist[i]<<" ";
		
	}
}

int main() {
	
	int V,E,s,d,w;
	
	cin>>V>>E;
	
	graph g(V);
	
	for( int i = 0 ; i < E ; i++ ){
		
		cin>>s>>d>>w;
		g.add_edge(s,d,w);	
	
	}
	
	g.longestPath(5);
	
	return 0;

}
