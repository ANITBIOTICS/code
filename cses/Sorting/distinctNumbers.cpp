#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long

int main(){
    ll n; cin >> n;
    vector<ll> arr(n);  

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    cout<< arr.size();
    
    return 0;
}
