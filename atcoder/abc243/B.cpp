#include<bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i: a)cin >> i;
    for (auto &i: b)cin >> i;
    int cnt = 0;
    map<int, int> frq1, frq2;
    for (auto i: a)frq1[i]++;
    for (auto i: b)frq2[i]++;
    long long c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            c1++;
            frq1[a[i]]--;
            frq2[b[i]]--;
        }
    }
    cout << c1 << endl;
    for (auto i: frq1) {
        int y = frq2[i.first];
        if (i.second > 0 and y > 0) {
            c2 += min(i.second, y);
        }
    }
    cout << c2 << endl;
}