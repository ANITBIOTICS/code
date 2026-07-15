#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, k; cin >> n >> k;
    vector<int> arr(k);
    ll x, a, b, c; cin >> x >> a >> b >> c;

    ll curr_xor = 0;
    ll ans = 0;

    for (ll i = 0; i < n; i++){
        int value = (int)x;
        if (i < k){
            // first window
            arr[i] = value;
            curr_xor ^= value;
        }else{
            // slide the window
            // remove old value, add new value
            ll index = i % k;

            curr_xor ^= arr[index];
            curr_xor ^= value;

            arr[index] = value;
        }

        if(i >= k -1){
            ans ^= curr_xor;
        }

        // next value
        x = (a * x + b) % c;

    }
    cout << ans << endl;
    return 0;
}


/*
A:  1 0 1 1 0 
B:  1 1 0 0 0
---------------------------
C:  1 1 1 1 0


0 0 = 0
1 0 = 
1 1 = 1 0 OR 1 1
*/