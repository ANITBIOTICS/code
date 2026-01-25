#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    
    int N;
    cin >> N;

    vector<int> arr(N - 1);
    for (int i = 0; i < N - 1; i++) cin >> arr[i];

    vector<int> diff(N);
    for (int i = 2; i < N; i++) diff[i] = arr[i - 1] - arr[i - 2];

    vector<int> res(N);
    vector<bool> used(N + 1);

    for (int first = 1; first <= N; first++) {
        res[0] = first;
        res[1] = arr[0] - first;

        for (int i = 2; i < N; i++) res[i] = res[i - 2] + diff[i];

        fill(used.begin(), used.end(), false);
        bool valid = true;

        for (int i = 0; i < N; i++) {
            if (res[i] < 1 || res[i] > N || used[res[i]]) {
                valid = false;
                break;
            }
            used[res[i]] = true;
        }

        if (valid) {
            for (int i = 0; i < N; i++) {
                if (i) cout << ' ';
                cout << res[i];
            }
            cout << '\n';
            return 0;
        }
    }

    return 0;
}