package CCC;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

public class j32025 {
    public static void main(String[] args){

        Scanner myObj = new Scanner(System.in);
        int n = myObj.nextInt();
        
        for(int i=0; i<n; i++){
            int sum = 0;
            String alex = myObj.next();
            String temp;
            Pattern pattern = Pattern.compile("-?\\d+");
            Matcher matcher = pattern.matcher(alex);
            StringBuilder sb = new StringBuilder();

            for(char a: alex.toCharArray()){
                if(Character.isUpperCase(a)){
                    sb.append(a);
                }
            }
            while (matcher.find()){
                temp = matcher.group();
                sum += Long.parseLong(temp);
            }
            sb.append(Integer.toString(sum));
            System.out.println(sb);
        }
        myObj.close();
    }
}
