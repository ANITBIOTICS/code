#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    string word; cin >> word;

    int r; cin >> r; 
    int c; cin >> c;
    
    int numWord = 0;

    vector<vector<char>> arr(r, vector<char>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[i][j];
        }
    }
    
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            for (int d = 0; d < 8; d++) {
                bool works = true;
                for (int k = 0; k < word.size(); k++) {
                    int nr = i + dx[d] * k;
                    int nc = j + dy[d] * k;

                    if (nr < 0 || nr >= r || nc < 0 || nc >= c || arr[nr][nc] != word[k]) {
                        works = false;
                        break;
                    }
                }
                if(works){
                    numWord++;
                }
            }
        }
    }
    cout << numWord;
    return 0;

}
