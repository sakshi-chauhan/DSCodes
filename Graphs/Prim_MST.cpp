//http://ideone.com/HTHpLI
//Prims using set

#include <iostream>
#include <set>
#include <climits>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main() {

	int V,E,s,d,w;
	cin>>V>>E;
	
	vvii graph(V);
	
	for( int i = 0 ; i < E ; i++ ){
		
		cin>>s>>d>>w;
		graph[s].push_back(make_pair(d,w));
		graph[d].push_back(make_pair(s,w));
		
	}
	
	vector<bool> disc(V,false);
	vi dist(V,INT_MAX);
	vi parent(V,-1);
	vii edge;
	
	int src;
	cin>>src;
	set<ii> Q;
	
	for( int i = 0 ; i < V ; i++ )
		Q.insert(make_pair(dist[i],i));
	
	Q.erase(Q.find(make_pair(dist[src],src)));	
	dist[src] = 0;
	Q.insert(make_pair(dist[src],src));
	
	while ( !Q.empty() ){
		
		ii top = *Q.begin();
		Q.erase(Q.begin());
		int v = top.second;
		
		disc[v] = true;
		
		if( v != src )
			edge.push_back(make_pair(parent[v],v));
		
		for(int i = 0 ; i < graph[v].size() ; i++ ){
			
			if( !disc[graph[v][i].first] ){
				
				int v2 = graph[v][i].first;
				int cost = graph[v][i].second;
				
				//cout<<"Cost = "<<cost;
				
				if( dist[v2] > cost ){
					
					Q.erase(Q.find(make_pair(dist[v2],v2)));
  					dist[v2] = cost;
  					Q.insert(make_pair(dist[v2],v2));
  					parent[v2] = v;
  				
  				}
				
			}
			
		}	
		
	}
	
	cout<<"MST edge set is"<<endl; 
	for( int i = 0 ; i<edge.size() ; i++ )
  			cout<<edge[i].first<<","<<edge[i].second<<endl;
	
	return 0;

}
