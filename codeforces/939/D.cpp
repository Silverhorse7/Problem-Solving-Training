#include "bits/stdc++.h"

using namespace std;
int n, m, k;
vector<pair<int, int> > e;
int p[500];

int find(int x) {
    if (x == p[x])
        return x;
    return x = find(p[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    p[a] = b;
}

signed main() {
    string a, b;
    cin >> n >> a >> b;
    for (int i = 1; i < 500; i++)
        p[i] = i;
    for (int i = 0; i <a.size(); i++)
        if (a[i] != b[i])
            e.emplace_back(a[i], b[i]);
    vector<pair<char, char> > ans;
    for (auto &pr: e) {
        if (find(pr.first) != find(pr.second)) {
            unite(pr.first, pr.second);
            ans.emplace_back(pr.first, pr.second);
        }
    }
    cout << ans.size() << endl;
    for (auto &pr: ans) {
        cout << pr.first << ' ' << pr.second << endl;
    }
}