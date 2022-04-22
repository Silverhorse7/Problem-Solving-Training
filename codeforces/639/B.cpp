#include<bits/stdc++.h>

using namespace std;

signed main() {
    int n, d, h;
    cin >> n >> d >> h;
    if (d > h + h) {
        cout << -1 << endl;
        return 0;
    }
    if (d == 1) {
        if (n == 2)
            cout << "1 2" << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int>> v;
    if (h == d) {
        for (int i = 2; i <= h + 1; i++)
            v.emplace_back(i - 1, i);
        for (int i = h + 2; i <= n; i++)
            v.emplace_back(2, i);
        if (v.size() > n - 1) {
            cout << -1 << endl;
            return 0;
        }
        for (auto[a, b]: v)
            cout << a << ' ' << b << endl;
        return 0;
    }
    for (int i = 2; i <= h + 1; i++)
        v.emplace_back(i - 1, i);
    v.emplace_back(1, 2 + h);
    for (int i = 3 + h; i <= d + 1; i++)
        v.emplace_back(i - 1, i);
    for (int i = d + 2; i <= n; i++)
        v.emplace_back(1, i);
    if (v.size() > n - 1) {
        cout << -1 << endl;
        return 0;
    }
    for (auto[a, b]: v)
        cout << a << ' ' << b << endl;
}