#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    ll n; cin >> n;
    if(n == 1){
        cout << 1;
    } else if(n <= 3 && n != 1){
        cout << "NO SOLUTION"; 
    }else{
        ll m = n/2;
        for(int i = n-1; i > 0; i--){
            cout << i<< " ";
            i--;
        }
        for(int i = n; i > 0; i--){
            cout << i << " ";
            i--;
        }
    }
    return 0;
}