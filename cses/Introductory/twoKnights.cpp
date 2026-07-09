#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll n; cin >> n;
    for(ll k = 1; k <= n; k++){
        ll ans = (k*k) * (k*k-1) / 2 - (4 * (k-1) * (k-2));
        cout << ans << endl;
    }
    return 0;
}