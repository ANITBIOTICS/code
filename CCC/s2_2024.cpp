#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int T, N;
    cin >> T >> N;

    for(int i = 0; i < T; i++){
        vector<int> frequency (26, 0);
        string S;
        cin >> S;
        for(char c: S) frequency[c - 'a']++;
        
        bool isTrue = true;
        for(int j = 1; j < N; j++){
            if((frequency[S[j]-'a'] > 1) == (frequency[S[j-1]-'a'] >1)){
                isTrue = false;
                break;
            }
        }
        cout << (isTrue ? 'T' : 'F') << "\n";
    }

   
    return 0;
}