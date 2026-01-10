

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int64 A, B, cA, cB, fA;
        cin >> A >> B >> cA >> cB >> fA;

        int64 k = B / cB;
        A += k * cA;
        B -= k * cB;

        if (A >= fA){
            cout << 0 << "\n";
            continue;
        }

        int64 lo = 0, hi = 1;
        while(!ok(A, B, cA, cB, fA, hi)){
            hi <<= 1;
            if (hi < 0){
                hi = (int64)4e18;
                break;
            }
        }

        while(lo < hi){
            int64 mid = lo + (hi - lo) / 2;
            if (ok(A, B, cA, cB, fA, mid)) hi = mid;
            else lo = mid + 1;
        }

        cout << lo << "\n";
    }
    return 0;
}
