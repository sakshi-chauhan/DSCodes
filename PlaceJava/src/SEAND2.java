/**
 *
 * @author CHAUHAN
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class SEAND2 {

    public static boolean nextPermutation(int[] p) {          
          //Step 1
          int a = p.length - 2;          
          while (a >= 0 && p[a] >= p[a + 1]) {              
              a--;          
          }          
          if (a == -1) {              
              return false;          
          }
          
          //Step 2
          int b = p.length - 1;          
          while (p[b] <= p[a]) {              
              b--;          
          }
          
          //Step 3
          int t = p[a];          
          p[a] = p[b];          
          p[b] = t;          
          
          //Step 4
          for (int i = a + 1, j = p.length - 1; i < j; i++, j--) {              
              t = p[i];              
              p[i] = p[j];
              p[j] = t;
          }
          return true;
      }
    public static void main(String[] args) throws IOException {
        
        int T,N,i,size;
        BigInteger A,res,min,ans;
        String str;
        int[] arr;
        long[] B;
        //StringBuffer result = new StringBuffer();
        //StringBuilder result = new StringBuilder();
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        T = Integer.parseInt(br.readLine());
        //T = sc.nextInt();
        
        while( T-- > 0 ){
        
            A = sc.nextBigInteger();
            //A = BigInteger.valueOf(br.readLine());
            str = A.toString();
            ans = A;
            size = str.length();
            arr = new int[size];
            
            for( i = 0 ; i < size ; i++){
                arr[i] = str.charAt(i) - '0';              
            }
            
            N = Integer.parseInt(br.readLine());
            //N = sc.nextInt();
            B = new long[N];
            
            for( i = 0  ;  i < N ; i++ ){
                B[i] = sc.nextLong();
            }
            
            res = new BigInteger("0");
            //System.out.println(A);
            for(i = 0 ; i < N ; i++ ){
                    res = res.add(A.mod(BigInteger.valueOf(B[i])));
                    //System.out.print(res+"  ");
            }
            //System.out.println();
            min = res;
            //System.out.println("min = "+min);
            while(nextPermutation(arr)){
                
                res = BigInteger.valueOf(0);
                StringBuffer result = new StringBuffer();
                for (i = 0; i < size; i++) {
                   //result.append( arr[i] );
                    result.insert(i, arr[i]);
                }
                str = result.toString();
                
                BigInteger A2 = new BigInteger(str);
                //System.out.println(A2);
                for(i = 0 ; i < N ; i++ ){
                    
                    res = res.add(A2.mod(BigInteger.valueOf(B[i]))); 
                    //System.out.print(res+"  ");
                    
                }
                if( res.compareTo(min) == -1 ){
                        min = res;
                        ans = A2;
                        if( min.equals(BigInteger.valueOf(0)) )
                           break;     
                        
                 }
            }
            System.out.println(ans);
        }
        
    }
    
}
