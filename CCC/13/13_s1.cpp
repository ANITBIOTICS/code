#include <bits/stdc++.h>
using namespace std;
#define ll long long

int findNumDigits(int n){
    int counter = 1;
    while(n/10 !=0){
        counter ++;
        n /= 10;
    }
    return counter;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int Y; cin >> Y;
    int numDigits = findNumDigits(Y);

    vector<int> arr;
    arr.reserve(numDigits);
    while(true){
        Y++;
        numDigits = findNumDigits(Y);
        arr.reserve(numDigits);
        for(int i = 0; i < numDigits; i++){
            arr.push_back((Y / (int)pow(10,i)) % 10);
        }
        sort(arr.begin(), arr.end());
        bool isOK = true;
        for(int i = 1; i < (int)arr.size(); i++){
            if(arr[i] == arr[i-1]){
                isOK = false;
                break;
            }
        }
        arr.clear();

        if(isOK){
            cout << Y << endl;
            break;
        }
    }
    return 0;
}