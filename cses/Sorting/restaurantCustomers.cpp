#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n; cin >> n;
    vector<pair<ll,ll>> arr;
    int numppl = 0;
    int maxppl = -1;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        arr.push_back({a, 1});
        arr.push_back({b, -1});
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        numppl += arr[i].second;
        maxppl = max(maxppl,numppl);
    
    }
    cout << maxppl << endl;
    
    return 0;
}
