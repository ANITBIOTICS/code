#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    ll curr = arr[0];
    ll best = arr[0];

    for(int i = 1; i < n; i++){
        curr = max(arr[i], curr+arr[i]);
        best = max(best, curr);
    }

    cout << best << endl;
    return 0;
}