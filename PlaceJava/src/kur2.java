
import java.math.BigInteger;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author CHAUHAN
 */
public class kur2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        
        BigInteger sum = BigInteger.ZERO ;
        BigInteger num = BigInteger.ONE;
        
        BigInteger a = new BigInteger("15");
        BigInteger b = new BigInteger("9");
        while( num.compareTo(a) != 0 ){
        
            sum.add(num.modPow(num.multiply(num), b));
            num.add(BigInteger.ONE);
        }
        System.out.println(sum);
    }
    
}
