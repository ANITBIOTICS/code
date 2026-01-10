#include <bits/stdc++.h>
using namespace std;

int cow(int number){
    int count = 0;
    for(int a = 2; a <= number; a++){
        int bessie = a;
        int elsie = a;
        int pow10 = 0;
        int temp = a;

        while(temp >= 10){
            temp = temp/10;
            pow10++;
        }

        temp = a;

        //bessie section:
        int digit = (bessie / (int)pow(10, pow10-1)) % 10;
        if((pow10!=0) && digit >= 5){
            digit ++;
        }
        bessie = digit * ((int) pow(10, pow10));

        //elsie section
        
        for(int i = 1; i <= pow10; i++){
            if ((a/(int) pow(10, i-1)) - (a/((int) pow(10, i))*10) >=5){
                elsie += pow(10,i);
            elsie = elsie - elsie%((int) pow(10, i));
            }
        }


    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
   return 0;
}