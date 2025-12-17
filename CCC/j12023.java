package CCC;
import java.util.Scanner;

public class j12023 {
    public static void main (String[] args){
        Scanner myObj = new Scanner(System.in);
        int P = myObj.nextInt();
        int C = myObj.nextInt();
        int sum = 50*P -10*C;
        if(P > C){
            sum += 500;
        }
        System.out.print(sum);
        myObj.close();
    }
}
