/**
 *
 * @author CHAUHAN
 */
import java.util.Scanner;
import java.util.HashMap;

public class B368 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int n,m,l;
        Scanner sc = new Scanner(System.in);
        HashMap<Integer,Boolean> hm = new HashMap<Integer,Boolean>();
        
        n = sc.nextInt();
        m = sc.nextInt();
        
        int []arr = new int[n]; 
        
        for( int i = 0 ; i < n ; i++ )
            arr[i] = sc.nextInt();
        
        for( int i = 0 ; i < m ; i++ ){
        
            l = sc.nextInt();
            
            for( int j = l-1 ; j < n ; j++ ){
            
                hm.put(arr[j], Boolean.TRUE);
          
            }
            System.out.println(hm.size());
            hm.clear();
        }
    }
    
}
