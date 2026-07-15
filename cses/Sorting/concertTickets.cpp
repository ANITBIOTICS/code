#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, m; cin >> n >> m;
    multiset<ll> tickets;
    for(int i = 0 ; i < n; i++){
        ll temp; cin >> temp; tickets.insert(temp);
    }
    for(int i = 0; i < m; i++){
        ll customer; cin >> customer;
        auto maxIndx = tickets.upper_bound(customer);
        if(maxIndx == tickets.begin()) cout << -1 << endl;
        else{
            maxIndx--;
            cout << *maxIndx << endl;
            tickets.erase(maxIndx);
        }
    }
    return 0;
}
