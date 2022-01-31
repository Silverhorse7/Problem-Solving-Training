#include<bits/stdc++.h>

using namespace std;
#define int long long 
void solve() {
    double hc,dc,hm,dm,k,w,a;
    cin>>hc>>dc>>hm>>dm>>k>>w>>a;
    int bc, bm, x, y;
    bc = ceil(hm/dc);
    bm = ceil(hc/dm);
    if (bc > bm) {
        for (int i = 0; i <= k; i++) {
            x = i;
            y = k - x;
            bc = ceil(hm / (dc + y * w));
            bm = ceil((hc + x * a) / dm);
            if (bc > bm) continue;
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--)solve();
}