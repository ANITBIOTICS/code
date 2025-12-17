package CCC;
import java.util.Scanner;

public class j22023 {
    public static void main (String[] args){
        Scanner myObj = new Scanner (System.in);
        int N = myObj.nextInt();
        int spicyness = 0; 
        for(int i = 0; i < N+1; i++){
            String temp = myObj.nextLine();
            if(temp.equals("Poblano")){
                spicyness += 1500;
            }else if(temp.equals("Mirasol")){
                spicyness += 6000;
            }else if(temp.equals("Serrano")){
                spicyness += 15500;
            }else if(temp.equals("Cayenne")){
                spicyness += 40000;
            }else if(temp.equals("Thai")){
                spicyness += 75000;
            }else if(temp.equals("Habanero")){
                spicyness += 125000;
            }
        }
    
        System.out.print(spicyness);
        myObj.close();
    }
          
}