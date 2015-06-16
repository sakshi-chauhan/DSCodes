import java.util.Stack;
import java.io.*;

public class IntoPost {

    public static Boolean isOperand(char ch){
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
    public static int prec(char ch){
    
        switch (ch){
            case '+':
            case '-':
                return 1;

            case '*':
            case '/':
                return 2;

            case '^':
                return 3;
        }
        
        return -1;
    }
    
    public static void convert(char s[]){
        
        int i,j=-1;
        Stack S = new Stack();
        
        for( i = 0 ; s[i]!='\0' ; i++ ){
            
            if( isOperand(s[i]) )
                System.out.print(s[i]+" ");
            
            else if( s[i] == '(')
                S.push(s[i]);
            
            else if (s[i] == ')'){
                
                char c = (char) S.pop();
                while(c != '(' && !S.empty()){
                
                    System.out.print(c);
                    c = (char) S.pop();
                    
                }
            }
            else{
                
                if( !S.empty() ){
                    char c = (char)S.peek();
                    if ( prec (c) >= prec (s[i]) && !S.empty()){

                        System.out.print(c);
                        S.pop();

                    }
                    S.push(s[i]);
                }
            }
        
        }
    
    }
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        
        //int n;
        char []c = new char[50];
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String str = br.readLine();
        
        for(int i = 0 ; i < str.length() ; i++ )
            c[i] = str.charAt(i);
        
        convert(c);
    }
    
}
