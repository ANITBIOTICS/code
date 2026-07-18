#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int&x : arr) cin >> x;
    vector<int> values = arr;
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for(int &x : arr)x = lower_bound(values.begin(), values.end(), x) - values.begin();
    vector<int> freq(values.size(), 0);
    set<pair<int,int>> ranking;

    for(int i = 0; i < k; i++){
        int x = arr[i];
        if(freq[x] > 0) ranking.erase({-freq[x], values[x]});

        freq[x]++;
        ranking.insert({-freq[x], values[x]});
    }

    cout << ranking.begin()->second << " ";

    for(int r = k; r < n; r++){
        int l = r-k;

        ranking.erase({-freq[arr[l]], values[arr[l]]});
        freq[arr[l]]--;

        if(freq[arr[l]] > 0) ranking.insert({-freq[arr[l]], values[arr[l]]});
        if(freq[arr[r]] > 0) ranking.erase({-freq[arr[r]], values[arr[r]]});
    

        freq[arr[r]]++;
        ranking.insert({-freq[arr[r]], values[arr[r]]});

        cout << ranking.begin()->second << " ";
    }

    cout << "\n";
    return 0;
}




/* #include <bits/stdc++.h>
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
    vector<pair<int,int>> ranking (values.size()); // {frequency, original value}
    
    for(int i = 0; i < values.size();i++) ranking[i].second = values[i];
    //first window
    for(int i = 0; i < k; i++){
        freq[arr[i]] ++;
        ranking[arr[i]].first ++;
    }
    vector<pair<int,int>> temp = ranking;
    sort(temp.begin(), temp.end());
    int maxfreq = temp.back().first;
    pair<int,int> thingthingy = {maxfreq, INT_MIN};
    auto othertemp = lower_bound(temp.begin(), temp.end(), thingthingy);
    cout << othertemp->second << " ";

    for(int r = k; r < n; r++){
        int l = r-k;
        
        freq[arr[l]]--;
        ranking[arr[l]].first--;
        
        freq[arr[r]]++;
        ranking[arr[r]].first++;

        temp = ranking;
        sort(temp.begin(), temp.end());

        maxfreq = temp.back().first;
        thingthingy = {maxfreq, INT_MIN};
        othertemp = lower_bound(temp.begin(), temp.end(), thingthingy);
        cout << othertemp->second << " ";
    
    }
    return 0;
}

*/