import java.io.*;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class BFS{
    
    HashMap<Integer, LinkedList<Integer>> adj;
    boolean visited[];
    
     BFS( int V ){
    
        adj = new HashMap<Integer, LinkedList<Integer>>();
        visited = new boolean[V];
     
        for( int i = 0 ; i < V ; i++ ){
            visited[i] = false;
            adj.put(i, new LinkedList<Integer>());
        }
    }
    
    public void add_edge( int a , int b ){
    
        adj.get(a).add(b);
        
    }
    
    public List<Integer> get_neighbour(int a){
        
        return adj.get(a);
        
    }
    
    public void BFS( int s ){
    
        visited[s] = true;
        System.out.print(s+ " ");
        
        
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(s);
        
        Iterator it = get_neighbour(s).iterator();
	
        while(it.hasNext()){
	    	
	    	s = (int)it.next();
                System.out.print(s+ " ");
                
	    	if( visited[s] == false){
                
                    visited[s] = true;
                    q.add(s);
                    
                }
	    			
        }  

    }
    
    public static void main(String[] args) {
 
        Scanner s = new Scanner(System.in);
        System.out.println("Enter No of Nodes");
        int V = s.nextInt();
 
	    BFS g= new BFS(V);
	    System.out.println("Enter No. Of Edges :");
	    int edges = s.nextInt();
 
	    for (int i = 0; i < edges ; i++) {
			int u = s.nextInt(); 
                        int v = s.nextInt();
			g.add_edge(u, v);
            }
 
	    System.out.println("Enter Source Vertex for DFS");
	    int source =s.nextInt(); 
            g.BFS(source);
	}
 
    
}


  
