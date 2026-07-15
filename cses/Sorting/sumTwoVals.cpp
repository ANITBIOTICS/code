#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, x; cin >> n >> x;
    vector<pair<ll,ll>> arr(n);
    for(int i = 0; i < n; i++){
        ll temp; cin >> temp;
        arr[i] = {temp, i+1}; //array with pairs of {value, original index}
    }
    sort(arr.begin(), arr.end());
    ll l = 0, r = n-1;

    while(l < r){ // or <=
        ll sum = arr[l].first + arr[r].first;
        if(sum == x){
            cout << arr[l].second << " " << arr[r].second << endl;
            return 0;
        }else if(sum < x) l ++;
        else r--;
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
