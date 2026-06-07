#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N; cin >> N;
    vector<int> day(5);
    int maxVal = -1;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int j =  0; j < s.length(); j++){
            if(s.substr(j, 1) == "Y"){
                day[j] ++;
                maxVal = (maxVal > day[j] ? maxVal : day[j]);
            }            
        }
    }
    int count = 0;
    for(int i = 0; i < 5; i++){
        if(day[i] == maxVal){
            count ++;
            if(count == 1){
                cout << i+1;
            }else{
                cout << "," << i+1;
            }            
        }
    }

    return 0;
}
