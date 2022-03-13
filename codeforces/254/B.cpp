#include "bits/stdc++.h"

using namespace std;
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    map<tuple<int, int, int>, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m, d, p, t;
        cin >> m >> d >> p >> t;
        m--;
        int y = 2013;
        while (t--) {
            d--;
            if (d == 0) {
                m--;
                if (m == -1)
                    m = 11, y = 2012;
                d = days[m];
            }
            mp[{m, d, y}] += p;
        }
    }
    int ans = 0;
    for (auto &it: mp) {
        ans = max(ans, it.second);
    }
    cout << ans;
    return 0;
}
