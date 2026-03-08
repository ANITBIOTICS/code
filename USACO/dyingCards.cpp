#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    int N, H; 
    cin >> N >> H;
    vector<ll> cards(N); 
    for(int i = 0; i < N; i++) cin >> cards[i];
    
    int k; 
    cin >> k;
    vector<bool> isWin(N, false);
    for(int i = 0; i < k; i++){
        int idx;
        cin >> idx;
        idx--;
        isWin[idx] = true;
    }

    int Q; 
    cin >> Q;
    vector<pair<ll, int>> queries(Q); // {time, original index}
    for(int i = 0; i < Q; i++){
        cin >> queries[i].first;
        queries[i].second = i;
    }
    
    sort(queries.begin(), queries.end());
    
    deque<int> hand;
    deque<int> draw;

    for(int i = 0; i < H; i++) hand.push_back(i);
    for(int i = H; i < N; i++) draw.push_back(i);
    
    vector<int> cycleOrder;
    for(int play = 0; play < N; play++){
        int winInHand = -1;
        ll minWinCost = LLONG_MAX;
        
        for(int idx : hand){
            if(isWin[idx] && (cards[idx] < minWinCost)){
                minWinCost = cards[idx];
                winInHand = idx;
            }
        }
        
        int cardToPlay;
        if(winInHand != -1){
            cardToPlay = winInHand;
        }else{
            ll minCost = LLONG_MAX;
            int minIndex = -1;
            for(int idx : hand){
                if(cards[idx] < minCost){
                    minCost = cards[idx];
                    minIndex = idx;
                }
            }
            cardToPlay = minIndex;
        }
        
        cycleOrder.push_back(cardToPlay);
        
        for(auto it = hand.begin(); it != hand.end(); it++){
            if(*it == cardToPlay){
                hand.erase(it);
                break;
            }
        }
        
        if(!draw.empty()){
            int newCard = draw.front();
            draw.pop_front();
            hand.push_back(newCard);
        }
        draw.push_back(cardToPlay);
    }
    
    vector<ll> prefixSum(N + 1, 0);
    vector<int> prefixWins(N + 1, 0);
    for(int i = 0; i < N; i++){
        prefixSum[i + 1] = prefixSum[i] + cards[cycleOrder[i]];
        prefixWins[i + 1] = prefixWins[i] + (isWin[cycleOrder[i]] ? 1 : 0);
    }
    
    vector<ll> time(N + 1, 0);
    for(int i = 1; i <= N; i++){
        time[i] = max(time[i - 1] + 1, prefixSum[i]);
    }
    
    vector<ll> answers(Q);
    
    ll cycleTime = time[N];
    ll cycleWins = prefixWins[N];
    
    int qIndex = 0;
    
    while(qIndex < Q){
        ll target = queries[qIndex].first;
        int originalIdx = queries[qIndex].second;
        
        if(target <= cycleTime){
            int l = 1, r = N;
            int best = 0;
            while(l <= r){
                int mid = (l + r)/2;
                if(time[mid] <= target){
                    best = mid;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            answers[originalIdx] = prefixWins[best];
            qIndex++;
        } 
        else{
            ll remainingTime = target - cycleTime;
            ll fullCycles = remainingTime/cycleTime;
            ll remainder = remainingTime%cycleTime;
            
            ll totalWins = cycleWins + fullCycles*cycleWins;
            
            if(remainder > 0){
                int l = 1, r = N;
                int best = 0;
                while(l <= r){
                    int m = (l + r) / 2;
                    if(time[m] <= remainder){
                        best = m;
                        l = m + 1;
                    }else{
                        r = m - 1;
                    }
                }
                totalWins += prefixWins[best];
            }
            
            answers[originalIdx] = totalWins;
            qIndex++;
        }
    }
    
    for(int i = 0; i < Q; i++){
        cout << answers[i] << "\n";
    }

    return 0;
}