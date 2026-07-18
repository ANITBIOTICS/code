#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, k; cin >> n >> k;
    vector<int> arr (n);
    for(int i = 0; i < n; i++) cin >> arr[i];\

    vector<int> values = arr; //array of not duplicates
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()),values.end());
    for(int &x : arr) x = lower_bound(values.begin(), values.end(), x) - values.begin();
    vector<int> freq (values.size(),0);
    

    //first window
    for(int i = 0; i < k; i++){
        if(freq[arr[i]] == 0)
        freq[arr[i]] ++;
    }


    for(int r = k; r < n; r++){

    }
    return 0;
}