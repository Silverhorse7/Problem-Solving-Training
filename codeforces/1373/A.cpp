#include "bits/stdc++.h"

using namespace std;
#define int long long

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a>=c)
            cout << -1 << ' ';
        else
            cout << 1 << ' ';
        if (c < a * b)
            cout << b << endl;
        else
            cout << -1 << endl;
    }
}