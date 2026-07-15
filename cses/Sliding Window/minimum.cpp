#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, k; cin >> n >> k;
    deque<pair<int,int>> dq; // window
    ll x, a, b, c; cin >> x >> a >> b >> c;
    ll ans = 0;
    
    for(int i = 0; i < n; i++){
        int curr = (int) x;

        while(!dq.empty() && dq.back().first >= curr){ //removing too large values
            dq.pop_back();
        }

        dq.push_back({x, i});

        while(!dq.empty() && dq.front().second <= i -k){ //rmove valuse outside of the window
            dq.pop_front();
        }

        if(i >= k - 1){ // a normal window
            ans ^= dq.front().first;
        }

        x = (a * x + b) % c;
    }
    
    //vector<ll> arr(k);
    // ll ans = 0;
    // ll minNum = LLONG_MAX;
    // for (ll i  = 0; i < k; i++){
    //     arr[i] = x;
    //     minNum = min(minNum, x);
    //     if (i != k -1){
    //         x = (a * x + b) % c;
    //     }
    // }

    // for(int i = k; i < n; i++){
    //     ll indx = i % k;
    //     x = (a * x + b) % c;
    //     ll temp = arr[indx];
    //     arr[indx] = x;

    //     if(temp == minNum){ // if you removed the old minimum, calculate min
    //         minNum = LLONG_MAX;
    //         for(ll m: arr){
    //             minNum = min(minNum, m);
    //         }
    //     }else{
    //         minNum = min(minNum, x);
    //     }

    //     ans ^= minNum;
    // }
    cout << ans << "\n";
    return 0;
}
