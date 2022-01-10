#include <bits/stdc++.h>

#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int a,b,c;
        cin>>a>>b>>c;
        if (b - a != c - b && !(a == b && b == c)) {
            if ((2 * b - c) % a == 0 && 2 * b - c > 0) {
                cout << "YES" << "\n";
            } else if ((2 * b - a) % c != 0 || 2 * b - a <= 0) {
                if ((a + c) % (2 * b) == 0) {
                    cout << "YES" << "\n";
                } else {
                    cout << "NO" << "\n";
                }
            } else {
                cout << "YES" << "\n";
            }
        } else {
            cout << "YES" << "\n";
        }
    }
}

