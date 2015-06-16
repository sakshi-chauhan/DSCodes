import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Rubanenko
 */
public class LCH15JEF {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		JustMultiply solver = new JustMultiply();
		solver.solve(1, in, out);
		out.close();
	}
}

class JustMultiply {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
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
            out.println(ans);
        }
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String nextLine() {
        String line = null;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return line;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(nextLine());
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
}