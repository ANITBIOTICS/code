#include <bits/stdc++.h>
using namespace std;

/* 
M -> M

O -> flip everything + "O"

OOMOO

Start from end, every letter in the back is untouched. not molested ;-;
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int T, k;
    cin >> T >> k; //# of test cases, k
    for(int i = 0; i < T; i++){
        int N; // will not exceed 4 * 10e5
        cin >> N;
        string S;
        cin >> S;
        int n = S.size();
        cout << "YES" << endl;

        if(k == 0) continue;
        
        string orderBackwards;
        vector<string> arr (S.size());

        for(int i = 0; i < S.size(); i++){
            arr[i] = S.substr(i, 1);
        }

        for(int i = n-1; i>=0; i--){
            if(arr[i] == "M"){
                orderBackwards.push_back('M');
            }else{ //its an O
                orderBackwards.push_back('O');
                for(int j = i-1; j >=0; j--){ //flip everythign before the O NOTE: CHECK THE STARTING AND ENDIGN POINTS
                    if(arr[j] == "M"){ // if its an M change it to an O
                        arr[j] = "O";
                    }else{
                        arr[j] = "M"; //if its an o change it to an m.
                    }
                }
            }
        }

        //put orderBackwards in normal order;
        reverse(orderBackwards.begin(), orderBackwards.end());
        cout << orderBackwards << endl;
    }
    return 0;
}