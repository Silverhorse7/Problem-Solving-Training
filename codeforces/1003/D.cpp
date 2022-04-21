#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (auto &i: a)
        cin >> i;
    map<int, int> exist;
    for (auto &i: a)
        exist[i]++;
    while (Q--) {
        int x;
        cin >> x;
        int ans = 0;
        for (int i = 4294967296; i > 0; i /= 2) {
            int need = min(x/i, exist[i]);
            ans += need;
            x -= (i) * need;
        }
        cout<<(x>0 ? -1 : ans)<<endl;
    }
}