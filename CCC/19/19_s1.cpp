#include <bits/stdc++.h>
using namespace std;

void vert(vector<vector<int>> &arr){
    int temp1 = arr[0][0];
    arr[0][0] = arr[0][1];
    arr[0][1] = temp1;

    temp1 = arr[1][0];
    arr[1][0] = arr[1][1];
    arr[1][1] = temp1;
}

void hori(vector<vector<int>> &arr){
    int temp1 = arr[0][0];
    arr[0][0] = arr[1][0];
    arr[1][0] = temp1;

    temp1 = arr[0][1];
    arr[0][1] = arr[1][1];
    arr[1][1] = temp1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    vector<vector<int>> arr = { {1, 2},
                                {3, 4}};

    string S; cin >> S;
    for(char a: S){
        if(a == 'H'){
            hori(arr);
        }else{
            vert(arr);
        }
    }

    cout << arr[0][0] << " " << arr[0][1] << endl;
    cout << arr[1][0] << " " << arr[1][1] << endl;

    return 0;
}