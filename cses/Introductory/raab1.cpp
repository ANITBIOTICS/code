#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        int n, a, b; cin >> n >> a >> b;
        // difference between a + b and n is the number of same-card's
        
        if (a + b > n || (a == 0) != (b == 0)){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        // player 1: natural ordering
        for(int j = 1; j <= n; j++) cout << j << " ";
        cout << " " << endl;

        int m = a + b;
        
        // player 2: cyclic shift the m cards
        int num = 1;

        // vector<int> secondPlayer;

        // for(int card = a + 1; card <= m; card++){
        //     secondPlayer.push_back(card);
        // }

        // for(int card = 1; card <= a; card++){
        //     secondPlayer.push_back(card);
        // }

        // for(int card = m+1; card <= n; card++){
        //     secondPlayer.push_back(card);
        // }

        for(int j = 0; j < m; j++){
            cout << ((m - b + num) % m == 0 ? m : (m - b + num) % m) << " ";
            num ++;
        }
        for(int i = m; i < n; i++){
            cout << num << " ";
            num ++;
        }


        // for(int x : secondPlayer) cout << x << " ";
    }
    return 0;
}

/*

1 2 3 4 5 | 6 7 
3 4 5 1 2 | 6 7
m = 5
a = 2
b = 3
*/