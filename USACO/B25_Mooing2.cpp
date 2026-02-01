#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

     int N;
     cin >> N;
     vector<int> arr(N);
     for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    vector<int> num(10e6);
    for(int a: arr){
        num[a] ++;
    }

    for(int a: arr){
        if(num[a] >=2){
            
        }
    }


    return 0;
}