
import java.math.BigInteger;
import java.util.Scanner;


public class NXTBIG {
    
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
    public static void main(String[] args) {
       
        int T,N;
        int[] arr;
        BigInteger n,k;
        String str;
        StringBuffer res,res2;// = new StringBuffer();
        Scanner sc = new Scanner(System.in);
    
        T = sc.nextInt();
    
        while( T-- > 0 ){
           
           N = sc.nextInt();      
           arr = new int[N];
           //n = BigInteger.ZERO;
           
           res = new StringBuffer(100007);
           for( int i = 0 ; i < N ; i++ ){
                arr[i] = sc.nextInt();
                //k = new BigInteger(Integer.toString(arr[i]));
                //n = n.multiply(new BigInteger("10"));
                //n = n.add(k);
                res.append(arr[i]);
           }
           
           
           str = res.toString();
           System.out.println(str);
           //n = new BigInteger(str);
           
           //res = new StringBuffer();
           //System.out.println(n);
           
           res2 = new StringBuffer(100007);
           //n = BigInteger.ZERO;          
           if( nextPermutation(arr) ){
               
               for( int i = 0 ; i < N ; i++ ){
                    
                    //k = new BigInteger(Integer.toString(arr[i]));
                    //n = n.multiply(new BigInteger("10"));
                    //n = n.add(k);
                    res2.append(arr[i]);
                    
               }
               str = res2.toString();
               System.out.println(str);
               // n = new BigInteger(str);
               //System.out.println(n);
               //System.out.println(res);
           }
            
           else
               System.out.println("NO NXTBIG");
    }
       
    }
    
}
