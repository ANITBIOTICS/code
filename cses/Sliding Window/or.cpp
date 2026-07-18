#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, k; cin >> n >> k;
    vector<int> arr(k);
    ll x, a, b, c; cin >> x >> a >> b >> c;

    ll p = 0, q = k, ans = 0;
    vector<ll> val(k), agg(k);

    for (ll i = 0; i < n; i++){
        ll curr = x;

        if (i >= k){
            if (q == k){
                for (ll j = k - 1; j >= 0; j--){
                    agg[j] = val[j];

                    if (j + 1 < k){
                        agg[j] |= agg[j + 1];
                    }
                }
                p = 0;
                q = 0;
            }


            q++;

        }

        val[p] = curr;

        if (p == 0)agg[p] = curr;
        else agg[p] = agg[p - 1] | curr;
    

        p++;

        if (i >= k - 1){
            ll incoming_or = (p == 0 ? 0 : agg[p - 1]);
            ll outgoing_or = (q == k ? 0 : agg[q]);
            ll window_or = incoming_or|outgoing_or;

            ans ^= window_or;
        }

        x =(a * x + b) % c;
    }

    cout << ans << '\n';
    return 0;
}


/*

you need to maintain the current window as an aggre queue that's formed by two stacks
an incoming one to store prefix OR and an outgoing to store suffix OR
OR of entiere widw = OR of two stack aggregates
every window always contains k elemenst os voth stacks can share the same two arryas
incoming stack: indices [0, p) and outgoing inddces [q, k)
when teh outgoing one is empty rebuild it from the incoming st ack by computing suffix ORs right to left

k = 4

0 3 8 11 10 2

A:  1 0 1 1 0 
B:  1 1 0 0 0
---------------------------
C:  1 1 1 1 0


0 0 = 0
1 0 = 
1 1 = 1 0 OR 1 1

*/