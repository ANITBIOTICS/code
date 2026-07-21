#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> freq(k+1, 0);
    set<int> missing;
    for(int i = 0; i <= k; i++) missing.insert(i);
    

    for(int i = 0; i < k; i++){
        if(arr[i] <= k){
            if(freq[arr[i]] == 0) missing.erase(arr[i]);
            freq[arr[i]]++;
        }
    }

    cout << *missing.begin() << " ";

    for(int r = k; r < n; r++){
        int l = r-k;

        if(arr[l] <= k){
            freq[arr[l]]--;
            if(freq[arr[l]] == 0) missing.insert(arr[l]);
            
        }

        if(arr[r] <= k){
            if(freq[arr[r]] == 0) missing.erase(arr[r]);
            

            freq[arr[r]]++;
        }

        cout << *missing.begin() << " ";
    }

    cout << "\n";
    return 0;
}