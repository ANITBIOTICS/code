#include <bits/stdc++.h>
using namespace std;

int cow(int number){
    int count = 0;
    for(int a = 2; a <= number; a++){
        int bessie = a;
        int temp = a;
        int b = 0;

        while(temp >= 10){
            temp = temp/10;
            b++;
        }
        //b is the power of 10 in this number a 

        if(b!= 0  && (a/(int) pow(10, b-1)) - (a/((int) pow(10, b))*10) >=5){
            bessie += pow(10,b);
        }
        
        bessie = bessie - bessie%((int) pow(10, b));


        int elsie = a;
        for(int i = 1; i <= b; i++){
            if ((a/(int) pow(10, i-1)) - (a/((int) pow(10, i))*10) >=5){
                elsie += pow(10,i);
            elsie = elsie - elsie%((int) pow(10, i));
            }
        }

        if(elsie != bessie){
            count ++;
        }
    }   
    return count;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    /*
    int N;
    cin >> N;
    
    vector<int> arr (N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
   */
    cout << cow(100);
    return 0;
}