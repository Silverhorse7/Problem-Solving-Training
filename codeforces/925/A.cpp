#include "bits/stdc++.h"

using namespace std;
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

int main() {
    int n, m, ns, ne, v;
    cin >> n >> m >> ns >> ne >> v;
    const int sz = max(ns, ne) + 1;
    vector<int> s(sz), e(sz);
    for (int i = 1; i <= ns; i++)
        cin >> s[i];
    for (int i = 1; i <= ne; i++)
        cin >> e[i];
    int Q;
    cin >> Q;
    while (Q--) {

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 1e9;
        if (x1 == x2) ans = abs(y2 - y1);
        else {
            int j = lower_bound(s.begin()+1,s.begin()+ns, min(y1, y2)) - s.begin();
            if (j <= ns) {
                ans = min(ans, abs(y2 - s[j]) + abs(y1 - s[j]) + abs(x1 - x2));
            }
            if (j > 1) {
                ans = min(ans, abs(y2 - s[j - 1]) + abs(y1 - s[j - 1]) + abs(x1 - x2));
            }
            j = lower_bound(e.begin()+1, e.begin() + ne, min(y1, y2)) - e.begin();
            if (j <= ne) {
                ans = min(ans, abs(y2 - e[j]) + abs(y1 - e[j]) + (abs(x1 - x2) + v - 1) / v);
            }
            if (j > 1) {
                ans = min(ans, abs(y2 - e[j - 1]) + abs(y1 - e[j - 1]) + (abs(x1 - x2) + v - 1) / v);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
