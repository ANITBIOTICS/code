#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>> n;
    vector<ll> arr (n);
    ll total = 0;
    for(int i = 0; i < n; i++){
        cin>> arr[i];
        total += arr[i];
    }
 
    ll minimum = LLONG_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll s = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) s += arr[i];
        minimum = min(minimum, llabs(total - 2 * s));
    }
    cout << minimum << "\n";
    return 0; 
}