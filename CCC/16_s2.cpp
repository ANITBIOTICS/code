#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
max speeds  = pair highers P wiht lowest D, lowest D with highest P??
lowest speeds s= pair peopel of equal speeds
*/

void minSpeed(int num){
    vector<int> dSpeeds(num);
    vector<int> pSpeeds(num);

    for(int i = 0; i < num ; i++){
        cin >> dSpeeds[i];
    }
    sort(dSpeeds.begin(), dSpeeds.end());

    for(int i = 0; i < num ; i++){
        cin >> pSpeeds[i];
    }
    sort(pSpeeds.begin(), pSpeeds.end());

    ll sumSpeed = 0;
    for(int i = 0; i < num; i++){
        sumSpeed += max(dSpeeds[i], pSpeeds[i]);
    }
    cout << sumSpeed;
}

void maxSpeed(int num){
    vector<int> dSpeeds(num);
    vector<int> pSpeeds(num);

    for(int i = 0; i < num ; i++){
        cin >> dSpeeds[i];
    }
    sort(dSpeeds.begin(), dSpeeds.end());

    for(int i = 0; i < num ; i++){
        cin >> pSpeeds[i];
    }
    sort(pSpeeds.begin(), pSpeeds.end());

    ll sumSpeed = 0;
    for(int i = 0; i < num; i++){
        sumSpeed += max(dSpeeds[i], pSpeeds[num - i - 1]);
    }
    cout << sumSpeed;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int question; cin >> question;
    int num; cin >> num;
    if(question == 1){
        minSpeed(num);
    }else{
        maxSpeed(num);
    }
    return 0;
}