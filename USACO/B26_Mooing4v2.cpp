#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, k;
    cin >> T >> k;

    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        cout << "YES" << endl;
        if (k == 0) continue;

        string res;

        int flip = 0;
        for (int i = (int)S.size() - 1; i >= 0; --i) {
            char c = S[i];
            if (flip) c = (c == 'M' ? 'O' : 'M');
            res.push_back(c);
            if (c == 'O') flip ^= 1;
        }

        reverse(res.begin(), res.end());
        cout << res << "\n";
    }
    return 0;
}
