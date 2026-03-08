#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    ll n; cin >> n;
    vector<pair<int,int>> coords(n);
    ll size = 0;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        ll y; cin >> y;
        size = max(size, max(x, y));
        coords[i] = {x,y};
        }

        vector<vector<int>> arr (size, vector<int>(size));

        int num = 1;
        int side = 1;
        bool toggle = true; //true means down left, false means right up
        while(side <= size){
            if(toggle){
                for(int i = 0; i < side; i++){ //going down
                    arr[i][side-1] = num; 
                    num++;
                }
                for(int j = side-2; j >= 0; j--){ //going left
                    arr[side-1][j] = num;
                    num++;
                }
            }else{ 
                for(int j = 0; j < side; j++){ //going right
                    arr[side-1][j] = num;
                    num++;
                }
                for(int i = side-2; i>=0; i--){
                    arr[i][side-1] = num;
                    num++;
                }

            }
            toggle = !toggle;
            side ++;
        }

        for(auto x: coords){
            cout << arr[x.second-1][x.first-1] << endl;
        }
    return 0;
}