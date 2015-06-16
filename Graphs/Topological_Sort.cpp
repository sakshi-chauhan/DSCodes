//http://ideone.com/yw1EwR
//Topological Sorting of a graph

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class graph{

	int V;
	list<int> *adj;
	void Topological_Sort( int v , bool* visited , stack<int>& stk );
	
	public:
		graph( int V );
		void add_edge( int src , int dest );
		void TSort();
};

graph::graph( int ver ){
	
	V = ver;
	adj = new list<int>[V];	

}

void graph::add_edge( int src , int dest ){
	
	adj[src].push_back(dest);
	
}

void graph::Topological_Sort( int v , bool* visited , stack<int>& stk ){
	
	visited[v] = true;
	
	list<int>::iterator it;
	
	for( it = adj[v].begin() ; it != adj[v].end() ; it++ ){
		
		if( !visited[*it] )
			Topological_Sort( *it, visited , stk );
		
	}
	//cout<<v<<" pushed into stack.\n";
	stk.push(v);
}

void graph::TSort(){
	
	stack<int> stk;
	bool visited[V];
	
	for( int i = 0 ; i < V ; i++ )
		visited[i] = false;
		
	for( int i = 0 ; i < V ; i++ )
		if( !visited[i] )
			Topological_Sort(i,visited,stk);
	
	while( !stk.empty() ){
		
		cout<<stk.top()<<" ";
		stk.pop();
		
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
	
	g.TSort();
		
	return 0;
}
