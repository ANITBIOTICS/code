#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N; cin >> N;
    vector<int> values (N);
    vector<int> high (N/2), low (N/2);
    for(int i = 0 ; i < N; i++) cin >> values[i];

    sort(values.begin(), values.end());


    if(N%2 == 0){    
        for(int i = 0; i < N/2; i++){
            cout << values[N/2 - i-1] << " " << values[N/2+i] << " ";
        }
    }else{
        cout << values[N/2]; //printing median
        for(int i = 0; i < N/2; i++){
            cout << values[N/2 + 1 +i] << " " << values[N/2-1-i];
        }
    }


    return 0;
}