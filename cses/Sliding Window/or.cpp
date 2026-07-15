#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, k; cin >> n >> k;
    vector<int> arr(k);
    ll x, a, b, c; cin >> x >> a >> b >> c;

    ll curr_or = 0;
    ll ans = 0;

    // for (ll i = 0; i < n; i++){
    //     if (i < k){
    //         // first window
    //         arr[i] = x;
    //         curr_or ^= x;
    //     }else{
    //         // slide the window
    //         // remove old value, add new value
    //         ll index = i % k;

    //         curr_or ^= arr[index];
    //         curr_or ^= x;sss

    //         arr[index] = x;
    //     }

    //     if(i >= k -1){
    //         ans ^= curr_or;
    //     }

    //     // next value
    //     x = (a * x + b) % c;

    
    // cout << ans << endl;
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