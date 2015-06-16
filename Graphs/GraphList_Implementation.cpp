//http://ideone.com/qvENxn
//My first GRAPH, makes me nervous and scared

#include <iostream>
using namespace std;

struct graphNode{
	
	int dest;
	graphNode* next;
	
};

struct adjList{
	
	graphNode* head;
	
};

struct graph{
	
	int V;
	adjList* array;	
	
};

graphNode* newNode( int d ){
	
	graphNode *g = new graphNode();
	g -> dest = d;
	g -> next = NULL;
	
	return g;
	
}

graph* createGraph( int V ){
	
	graph* g = new graph;
	
	g -> V = V;
	g -> array = new adjList[V];
	
	for( int i = 0 ; i < V ; i++ )
		g->array[i].head = NULL;
	
	return g;
	
}

void addEdge( graph* g , int src , int dest ){
	
	graphNode* nn = newNode(dest);
	nn -> next = g->array[src].head;
	g -> array[src].head = nn;
	
}

void printGraph( graph* g ){
	
	for( int v = 0 ; v < g->V ; v++ ){
		
		cout<<"Adjacency list for vertex "<<v<<": head";
		graphNode* temp = g->array[v].head;
		
		while( temp ){
			
			cout<<"->"<<temp->dest;
			temp = temp->next;
			
		}
		cout<<"->NULL\n";
		
	}
}

int main() {
	
	
	int V,E,s,d;
	cin>>V>>E;
	graph *g = createGraph(V);
	
	for( int i = 0 ; i < E ; i++ ){
		
		cin>>s>>d;
		addEdge( g , s , d);
		
	}

	printGraph(g);

	return 0;

}
