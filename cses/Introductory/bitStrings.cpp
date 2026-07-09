#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
// ll power(ll base, ll exp, ll mod){
//     ll result = 1;
 
//     while(exp > 0){
//         if (exp % 2 == 1){
//             result = (result * base) % mod;
//         }
//         base = (base * base) % mod;
//         exp /= 2;
//     }
//     return result;
// }
 
int main(){
    ll n; cin >> n;
    const ll MOD = 1000000007;
    // cout << power(2, n, MOD) << endl;
    ll result = 1;
    for(int i = 0; i < n; i++){
        result = (result * 2) % MOD;
    }
    cout << result << endl;
    return 0;
