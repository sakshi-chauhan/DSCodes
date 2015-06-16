//http://ideone.com/oWjUdR
//Detect cycle in an undirected graph using UNION FIND algorithm

#include <iostream>
using namespace std;

//int parent[3] = {-1,-1,-1};

struct Edge{
	
	int src;
	int dest;
	
};

class graph{
	
	int V,E;
	Edge* edge;
	
	public:
		graph( int , int );
		int find( int* , int );
		void Union( int* , int , int );
		bool isCyclic();
		void add_edge( int , int , int );
		
};

graph::graph( int V , int E ){
	
	this->V = V;
	this->E = E;
	edge = new Edge[E];
	
}

int graph::find( int* parent , int x ){
	
	//cout<<"Find"<<x<<"\n";
	//cout<<parent[x];
	if( parent[x] == -1 )
		return x;
	
	return find( parent , parent[x] );	
	
}

void graph::Union( int* parent , int a , int b ){
	
	int a_par = find(parent,a);
	int b_par = find(parent,b);
	
	parent[a_par] = b_par;
	//cout<<"parent of"<<a_par<<" is "<<b_par;

}

void graph::add_edge( int i , int s , int d ){
	
	edge[i].src = s;
	edge[i].dest = d;
	
	//cout<<edge[i].src<<" "<<edge[i].dest<<"\n";
	
}

bool graph::isCyclic(){
	
	int* parent = new int[V];
	for( int i = 0 ; i < V ; i++ )
		parent[i] = -1;
	
	for( int i = 0 ; i < E ; i++ ){
		
		//cout<<edge[i].src<<" "<<edge[i].dest<<"\n";	
		int x = find( parent , edge[i].src );
		int y = find( parent , edge[i].dest );
		
		//cout<<x<<" "<<y;
		
		if( x == y )
			return true;
		
		Union(parent,x,y);
		
	}	
	
	return false;
	
}

int main() {
	
	int V,E,s,d;
	
	cin>>V>>E;
	
	graph g( V, E );
	
	for( int i = 0 ; i < E ; i++ ){
		
		cin>>s>>d;
		g.add_edge( i, s , d );
	
	}
	
	//for( int i = 0 ; i < E ; i++ )
		//cout<<g.edge[i].src<<" "<<g.edge[i].dest<<"\n";
	
	if( g.isCyclic() )
		cout<<"The graph has a cycle";
	else
		cout<<"The graph is acyclic";
	
	return 0;
}
