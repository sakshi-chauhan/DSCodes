package p4;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author CHAUHAN
 */
public class p4 {

    /**
     * @param args the command line arguments
     * @throws java.io.FileNotFoundException
     */
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException, NullPointerException {
        // TODO code application logic here
        
        BigInteger n,res,c1,c2,c3,c4,c5,c6;
        String str;
       
        BufferedReader fin = new BufferedReader(new FileReader("input4.txt"));
        BufferedReader fout = new BufferedReader(new FileReader("output4.txt"));
        Scanner sc = new Scanner(System.in);
        str = fin.readLine();
        //str = sc.next();
        n = new BigInteger(str);
        c1 = new BigInteger("37");
        c2 = new BigInteger("1303");
        c3 = new BigInteger("13628");
        c4 = new BigInteger("34664");
        c5 = new BigInteger("1368");
        c6 = new BigInteger("-1");
        
        while( !n.equals(c6)){
       
            res = (((((n.pow(3)).multiply(c1)).subtract((n.pow(2)).multiply(c2)).add(n.multiply(c3)).subtract(c4))).divide(c5));
            System.out.println(res);
            
            //str = sc.next();
            str = fin.readLine();
            n = new BigInteger(str);
           
        }
        
        fin.close();
        fout.close();
        
    }
    
}
