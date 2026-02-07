#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int N, Q;
    cin >> N >> Q;
    int temp;

    long long bigNum = (long long) 4e18;

    vector<long long> cost(61, bigNum);

    for(int i = 0; i < N; i++){
        long long temp;
        cin >> temp;

        if(i <= 60){
            cost[i] = temp; //minimum cost to buy i things. if  it would be more worth it to get 2 of the smaller deal
        }else{
            cost[60] = min(cost[60], temp);
        }
         //arr[i] means the  it costs to buy 2^i-1 buckets
    }

    for(int i = 1; i < 61; i++){
        cost[i] = min(cost[i], 2LL*cost[i-1]);
    }

    for(int i = 0; i < Q; i++){
        long long q;
        cin >> q;

        long long minCost = bigNum;
        long long curCost = 0;

        for(int j = 60; j >= 0; j--){
            long long power = 1LL << j;
            long long k = q/power;

            curCost += k * cost[j];
            q = q - k * power;

            if (q > 0){
                minCost = min(minCost, curCost + cost[j]);
            }else{
                minCost = min(curCost, minCost); 
            }
        }
        cout << minCost << endl;
    }

    return 0;
}