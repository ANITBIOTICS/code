#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int T, k;
    cin >> T >> k;

    for(int i = 0; i < T; i ++){
         int N;
        cin >> N;
        string S;
        cin >> S;

        int len = N * 3;

        //unable to dissapear
        if(N % 2 == 1){
            cout << -1 << "\n";
            continue;
        }

        //one operation
        if(S.substr(0, len/2) == S.substr(len/2)){
            cout << 1 << "\n"; //output M
            for(int j = 0; j < len; j++){
                cout << 1 << (j + 1 == len ? '\n' : ' ');
            }         
            continue;
        }

        //do it in 2 operations
        cout << 2 << endl; //ouput M
        vector <int> res (len, 2);
        int halfLen = len/2;

        for(int i = 0; i < N/2; i++){
            int l = 3*i;
            int r = halfLen + 3*i;

            string a = S.substr(l, 3);
            string b = S.substr(r, 3);

            if(a == b){
                
            }
        }



            
        



    }




    return 0;
}