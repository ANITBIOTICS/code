#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    ll n; cin >> n;
    vector<int> arr (n, 0);
    for(int i = 0; i < n-1; i++){
        ll temp; cin >> temp; temp--;
        arr[temp] = 1;
    }
    for(int i = 0; i < n; i++){
        if(arr[i]==0){
            cout << i+1;
            break;
        }
    }
    return 0;

}