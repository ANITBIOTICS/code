#include <bits/stdc++.h>
using namespace std;

/*
the order of the cows doesn't matter
*/

int main(){

    int N; 
    cin >> N;
    vector<int> arr (N);

    for(int i = 0; i < N; i++){ //input all of the max cow tuitions. 
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long bestSum = 0;
    long long bestCost = 0;
    
    for(int cost = 0; cost <=arr[N-1]; cost++){ //  a loop going through all the values from cost = 0 to cost = the largest value a cow is willing to pay
        long long  numCows = 0;
        long long sum = 0;

        for(int j = 0; j < N; j++){ //summing up the total number of cows willing to pay tuition at price cost;
            if(cost <= arr[j]){
                numCows ++;
            }
        }

        sum = numCows * cost; // could technically do this inside of the if statement but wtv

        if(sum > bestSum){
            bestCost = cost;
            bestSum = sum;
        }
    }
    cout << bestSum << " " << bestCost;
    return 0;
}