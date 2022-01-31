#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int j = 0;;) {
        int z = 0, o = 0;
        for (int i = j; i < s.size(); i++) {
            s[i] == '0' ? z += 1 : o += 1;
        }
        if (z != o)cnt = min(z, o);
        else {
            z = 0, o = 0;
            for (int i = j; i < s.size() - 1; i++) {
                s[i] == '0' ? z += 1 : o += 1;
            }
            if (z != o)cnt = max(cnt, min(z, o));
            z = 0, o = 0;
            for (int i = j + 1; i < s.size(); i++) {
                s[i] == '0' ? z += 1 : o += 1;
            }
            if (z != o)cnt = max(cnt, min(z, o));
        }
        break;
    }
    cout << cnt << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--)solve();
}