#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v)cin >> i;
    ll ans = INT_MAX;
    for (int i = 1; i <= 1000; i++) {
        ll total = 0;
        for (auto j : v) total += (j - i) * (j - i);
        ans = min(ans, total);
    }
    cout << ans;
}