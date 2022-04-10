#include<bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 32768;
int n, x, a[mod + 3];
vector<int> l[mod + 3];
queue<int> s;

signed main() {
    memset(a, -1, sizeof(a));
    for (int i = 0; i < mod; i++) {
        l[(i + 1) % mod].push_back(i);
        l[(i * 2) % mod].push_back(i);
    }
    s.push(0);
    auto condit = [&](int x, int from) -> long long {
        if (a[x] == -1) {
            a[x] = a[from] + 1;
            s.push(x);
        }
        return 1LL;
    };
    while (!s.empty()) {
        x = s.front();
        s.pop();
        for (int tmp: l[x]) {
            condit(tmp, x);
        }
    }
    cin >> n;
    vector<int> v(n);
    for (auto &i: v)
        cin >> i, cout << a[i] << ' ';
}