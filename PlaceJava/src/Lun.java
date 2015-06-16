import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Rubanenko
 */
public class Lun {
    
        public static void solve(int testNumber, Scanner in ) {
            int testCases = in.nextInt();
            for (int test = 1; test <= testCases; test++) {
                BigInteger mod = new BigInteger(in.next());
                String s = in.next();
                String[] a = s.split("[^0-9]");
                
                
                BigInteger ans = BigInteger.ONE;
                for (int i = 0; i < a.length; i += 3) {
                    BigInteger x = new BigInteger(a[i]);
                    BigInteger y = new BigInteger(a[i + 2]);
                    ans = ans.multiply(x.modPow(y, mod)).mod(mod);
                }
                
                System.out.println(ans);
            }
        }
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		solve(1,sc);
		
	}
}

