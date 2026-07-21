#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int&x : arr) cin >> x;

    vector<int> values = arr;
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()),values.end());

    for(int &x : arr) x = lower_bound(values.begin(), values.end(), x) - values.begin();
    vector<int> freq(values.size(),0);
    
    int distinct = 0;
    for(int i = 0; i < k; i++){
        if(freq[arr[i]] == 0) distinct ++;
        freq[arr[i]] ++;
    }
    cout << distinct << " ";

    for(int r = k; r < n; r++){
        int l = r-k;

        freq[arr[l]] --;
        if(freq[arr[l]] == 0) distinct --;

        freq[arr[r]] ++;
        if(freq[arr[r]] == 1) distinct ++;

        cout << distinct << " ";
    }

    return 0;
}