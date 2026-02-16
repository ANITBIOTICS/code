#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int N; cin >> N;


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pair(time, position0
    for(int i = 0; i < N; i++){
        int time, position;
        cin >> time >> position;
        pair<int, int> temp = {time, position};
        pq.push(temp);
    }

    pair<int, int> prev = pq.top();
    pq.pop();
    int prevTime = prev.first;
    int prevPosition = prev.second;
    double speed = -1.0;
    
    while(pq.size() > 0){
        pair<int, int> temp = pq.top();
        pq.pop();

        int time = temp.first;
        int position = temp.second;

        double tempSpeed = (1.0*abs(position - prevPosition))/abs(time - prevTime);
        speed = max(speed, tempSpeed);

        prevTime = temp.first;
        prevPosition = temp.second;
    }

    cout << speed;


    return 0;
}