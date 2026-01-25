#include <bits/stdc++.h>
using namespace std;

/*
the order of the cows doesn't matter
*/

int main(){

    int N; 
    cin >> N;
    vector<int> arr (N);

    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    long long sum = -1;
    long long cost = 0;
    for (int i = 0; i < N; i++){
        long long amt = arr[i];
        long long tempSum = amt * (i-1);

        if(tempSum >= sum){
            sum = tempSum;
            if(amt > cost) cost = amt;
        }
    }

    
    return 0;
}


/*
faster method, find the number of times tuition increases. then calculate the sum for each jump intuition.

*/