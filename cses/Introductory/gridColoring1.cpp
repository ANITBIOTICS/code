#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n, m; cin >> n >> m;
    vector<string> arr (n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<char> cha = {'A', 'B', 'C','D'};
    // 0, 1, 2, 3 be A B C D respectively

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vector<bool> used = {false, false, false, false};
            used[arr[i][j] - 'A'] = true;
            if(i > 0) used[arr[i-1][j] - 'A'] = true;
            if( j > 0) used[arr[i][j-1] - 'A'] = true;
            for(int k = 0; k < 4; k++){
                if(!used[k]){
                    arr[i][j] = cha[k];
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    
    return 0;
}
