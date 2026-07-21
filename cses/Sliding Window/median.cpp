#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    multiset<int> low, high;

    vector<int> temp (k);
    // seperate for the first winndow
    for(int i = 0; i < k; i++){
        temp[i] = arr[i];
    }

    sort(temp.begin(), temp.end());
    for(int i = 0; i < k; i++){
        if(arr[i] < arr[(k+1)/2]) low.insert(arr[i]);
        else high.insert(arr[i]);
    }

//median should be the last value of low
//if low.size() < n1, take the firs tvalue of high and put it in low? vice verssa
    int n1 = (k+1)/2; //size of low
    int n2 = k - n1; // size of high
    for(int r = k; r < n; r++){
        int l = r - k;


    }

}

/*
8 3
2 4 3 5 8 1 2 1

*/
















/*

use two multisets to maintian the current iwnodw in sorted halves
for the required smaller median, maintain
|low| = ceil(k/2)  = k+1/2
e.g. if k = 4 then your smalller mu ltiset contains two smallest s elemtns so its largets elmetn i the smaller of the two middle values
for eeach new elemtn, insert into one of the multisets, remove elemtn leaving the window, rebalance the multisets, output *low.rbegin()
cuz multisets alloow duplicate thwey wokr just fine
maintain |low| = k +1 / 2
and every elemtn in low is at most eveyr elmet in high
when low has too many elments, move its largest to high
when low has too few elmetns, mover smallest element of highj t o low

*/