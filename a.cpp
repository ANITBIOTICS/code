#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, k; cin >> n >> k;
    vector<int> arr(k);
    ll x, a, b, c; cin >> x >> a >> b >> c;

    ll curr_xor = 0;
    ll ans = 0;
    ll thing = 0;
    for(int i = 0; i < k; i++){
        arr[i] = x;
        thing ^= x;

        if(i != k-1) x = (a * x + b) % c;
    }
    ans ^= thing;

    for(ll i = k; i < n; i++){
        ll indx = i % k;
        x = (a * x + b) % c;

        thing |= arr[indx]; //remove
        thing |= x; //add
        arr[indx] = x; // update window

        ans ^= thing;
    }
    cout << ans << "\n";

    return 0;
}