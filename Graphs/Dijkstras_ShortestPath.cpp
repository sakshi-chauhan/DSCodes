//
//Implementing Dijkstra's with SET

#include <iostream>
#include <set>
#include <vector>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define mp make_pair
#define pb push_back 

int main() {
	
	int V,E,s,d,w,src;
	
	set<ii> Q;
	
	cin>>V>>E;
	
	vi dist(V,INT_MAX);
	vvii graph(V);
	for( int i = 0 ; i < E ; i++ ){
		
		cin>>s>>d>>w;
		graph[s].pb(mp(d,w));
		
	}
	
	cin>>src;
	dist[src] = 0;
	Q.insert(mp(0,0));
	
	while( !Q.empty() ){
		
		ii top = *Q.begin();
		Q.erase(Q.begin());
		
		int v = top.second;
		
		for( int i = 0 ; i < graph[v].size() ; i++ ){
			
			int u = graph[v][i].first;
			int cost = graph[v][i].second;
			
			if( dist[u] > dist[v]+cost ){
				
				if( u != src && dist[u] != INT_MAX )
					Q.erase(Q.find(mp(dist[u],u)));
				dist[u] = dist[v]+cost;
				Q.insert(mp(dist[u],u));
				
			}
		}
	}
	
	return 0;

}
