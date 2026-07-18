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
    ll distinct = 0;

    //first window
    for(int i = 0; i < k; i++){
        if(freq[arr[i]] == 0) distinct ++;
        freq[arr[i]] ++;
    }
    cout << distinct << " ";

    for(int r = k; r < n; r++){
        int l = r-k;
        if(--freq[arr[l]] == 0) distinct --;
        if(freq[arr[r]]++ == 0) distinct ++;
        cout << distinct << " ";
    }
    return 0;
}
/*

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    ll n, k; cin >> n >> k;
    unordered_map<ll, ll> frequency;
    ll counter = 0;
    vector<ll> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];

        if ((frequency[arr[i]]++) == 0) counter++;
        if (i >= k && (--frequency[arr[i-k]]) == 0) counter--; 

        if (i >= k-1) cout << counter << ' ';
    
    }

    return 0;
}
*/

/*  
    ll n, k; cin >> n >> k;
    vector<ll> arr(k);
    ll indx = 0;

    for(int i = 0; i < n; i++){
        ll temp; cin >> temp;

        arr[indx] = temp;
        indx = (indx+1)%k;

        if(i >= k-1){
            set<ll> s(arr.begin(), arr.end());
            cout << s.size() << " ";
        }
    }

vector<int> arr; cin >> arr
vector<int> values = arr
sort values
values.erase(unique())
for(int &x : arr) x = lower_bound(values.begin(), values.end(), x) - values.begin()
vector freq = values.size

*/