//http://ideone.com/658rF0
//Check whether the given graph is Bipartite

#include <iostream>
#include <list>
#include <queue>

using namespace std;

class graph{

	int V;
	list<int> *adj;
	
	public:
		graph( int V );
		void add_edge( int src , int dest );
		bool isBipartite( int src );
		
};

graph::graph( int ver ){
	
	V = ver;
	adj = new list<int>[V];	

}

void graph::add_edge( int src , int dest ){
	
	adj[src].push_back(dest);
	
}

bool graph::isBipartite( int s ){
	
	char color[V];
	int flag = 0;
	
	for( int i = 0 ; i < V ; i++ )
		color[i] = 'B';	//B stands for Black, meaning the vertex has not been touched yet
	
	color[s] = 'R';	//R for red
	queue<int> q;
	q.push(s);
	
	while( !q.empty() ){
		
		int v = q.front();
		q.pop();
		flag = 1 - flag;
		
		list<int>::iterator it;
		
		for( it = adj[v].begin() ; it != adj[v].end() ; it++ ){
			
			if( color[*it] == 'B' ){
			
				color[*it] = ( flag == 0 )?'R':'B';
				q.push(*it);
			
			}
			
			else if( color[*it] == color[v] )
				return false;
			
		}
		
	}
	
	return true;

}

int main() {

	int V,E,s,d;
	
	cin>>V>>E;
	
	graph g(V);
	
	for( int i = 0 ; i < E ; i++ ){
		
		cin>>s>>d;
		g.add_edge(s,d);	
	
	}
	
	if( g.isBipartite(5) )
		cout<<"Graph is bipartite";
	else
		cout<<"Non bipartite";
	
	return 0;

}
