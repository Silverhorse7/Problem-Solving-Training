#include "bits/stdc++.h"

using namespace std;

bool chk(vector<int> v, int n) {
    map<int, int> x;
    for (auto i: v)
        x[i % 2]++;
    if (x.size() > 1)
        return 0;
    for (auto i: v)
        if (i <= 0)return 0;
    vector<int> ans = v;
    int cnt = 0;
    for (auto i: v)cnt += i;
    if (cnt != n)return 0;
    cout << "Yes" << endl;
    for (auto i: ans)cout << i << ' ';
    cout << endl;
    return 1;
}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        bool x = 0;
        vector<int> ans;
        ans.push_back(2 * (n / 2 - (m - 1)));
        for (int i = 0; i < m - 1; i++)
            ans.push_back(2);
        sort(ans.begin(), ans.end());
        if (ans.front() < 0)x = 1;
        if (chk(ans, n)) {
            continue;
        }
        ans.clear();
        int y = n;
        for (int i = 0; i < m - 1; i++)
            ans.push_back(1), n--;
        ans.push_back(n);
        if (chk(ans, y))
            continue;
        cout << "NO" << endl;
    }

}