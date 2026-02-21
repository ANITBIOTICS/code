#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sum(int start, int end, vector<int> arr){
    //finds the sum of the 4 carts starting from the given one;
    int sum = 0;
    for(int i = 0; i < end-start; i++){
        sum += arr[start+i];
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int finalCar = -1;
    int maxWeight; cin >> maxWeight;
    int numCar; cin >> numCar;
    for(int i = 0; i < 4; i++){ //when the bridge isnt full

    }
    for(int i = 0; i < numCar-4; i++){
        if()
    }
    return 0;
}