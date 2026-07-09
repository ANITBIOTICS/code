#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n; cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++)cin >> arr[i];
    ll counter = 0;
    for(int i = 1; i < n ; i++){
        if(arr[i]>= arr[i-1]){
            continue;
        }else{
            counter += (arr[i-1]-arr[i]);
            arr[i] = arr[i-1];
        }
    }
    cout << counter;
    return 0;
}