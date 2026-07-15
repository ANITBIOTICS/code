#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n; cin >> n;
    vector<pair<ll,ll>> arr;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        arr.push_back({b, a});
    }
    sort(arr.begin(), arr.end());
    ll counter = 0; 
    ll ending = -1;
    for(int i = 0; i < arr.size(); i++){
        auto temp = arr[i];
        if(temp.second >= ending){
            counter ++;
            ending = temp.first;
        }
    }
    cout << counter << endl;
    return 0;
}
