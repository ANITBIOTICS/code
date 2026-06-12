#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    // ll n; cin >> n;
    string s; cin >> s;
    vector<int> count(26, 0);
    for(char a: s) count[a -'A']++;
    
    int indexOne = -1;
    int numOne = 0;
    for(int i = 0; i < 26; i++){
        if(count[i]%2 == 1){
            numOne ++;
            if(numOne == 1) indexOne = i;
        }
    }
    
    if(numOne > 1 ){cout << "NO SOLUTION"; return 0;}

    string res = "";
    if(indexOne != -1){res = res + char(indexOne+'A'); count[indexOne]--;}
    for(int i = 0; i < 26; i ++){
        if(count[i] == 0) continue;
        for(int j = 0; j < count[i]; j+=2){
            res = char(i+'A') + res + char(i+'A');
        }
    }

    cout << res;
    return 0;
}