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
            cout << 1 << "\n";
            for(int j = 0; j < len; j++){
                cout << 1 << (j + 1 == len ? '\n' : ' ');
            }
          
            continue;
        }

        if(k == 1){
            cout << 3 << "\n";
            for(int i = 0; i < 3 * N; i++){
                string str = S.substr(i, 1);
                if(str == "C"){
                    cout << 1 << " ";
                }else if (str == "O"){
                    cout << 2 << " ";
                }else{
                    cout << 3 << " ";
                }
            }
            cout << endl;
            continue;
        }else{ // k = 0
            
        }



    }




    return 0;
}