#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int K; cin >> K;
    vector<int> arr;
    arr.reserve(K);
    for(int i = 0; i < K; i++){
        arr.push_back(i+1);
    }

    int m; cin >> m;

    for(int i = 0; i < m; i++){
        int multiple; cin >> multiple;
        vector<int> temp; temp.reserve((int)arr.size());
        for(int i = 0; i < (int) arr.size(); i++){
            if((i+1)%multiple != 0) temp.push_back(arr[i]);
        }
        arr.swap(temp);      

    }

    for(int x: arr){
        cout << x << endl;
    }

    return 0;
}