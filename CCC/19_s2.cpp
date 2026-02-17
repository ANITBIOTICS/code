#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n<2 || n%2 == 0) return false;
    for(int i = 3 ; i <= sqrt(n); i++) if(n%i == 0) return false;
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin .tie(nullptr); 
    int N; cin >> N;

    for(int i = 0; i < N; i++){
        int n; cin >> n;

        for (int j = 0; j < n * 2; j++){
            if(isPrime(j) && isPrime(n*2-j)){
                cout << j << " " << n*2-j << endl;
                break;
            }
        }

    }
    return 0;
}   