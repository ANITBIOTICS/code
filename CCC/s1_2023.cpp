#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int C; 
    cin >> C;

    vector<vector<int>> arr (2, vector<int>(C, 0));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j]; //1 means black, 0 means white
        }
    }

    int perimeter = 0;
    
    for(int r = 0; r < 2; r++){
        for(int c = 0; c < C; c++){
            if(arr[r][c] == 1){

                perimeter += 3;

                if(c + 1 < C && arr[r][c + 1] == 1){
                    perimeter -= 2;
                }

                if(r == 0 && c % 2 == 0 && arr[1][c] == 1){
                    perimeter -= 2;
                }
            }
        }
    }

    cout << perimeter << endl;
    return 0;
}