#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 69;
int a[N];
ll n;

int lower(vector<ll> x, int val) {
    int start = 0;
    int end = x.size() - 1;
    int target = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (x[mid] <= val) {
            start = mid + 1;
            target = mid;
        } else {
            end = mid - 1;
        }
    }
    return target;
}

signed main() {
    ios_base::sync_with_stdio();
    cin >> n;
    vector<ll> v(n);
    for (auto &b :v)cin >> b;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        int cnt = 1;
        while (i < n and v[i] <= v[i - 1] * 2) {
            i++;
            cnt++;
            ans = max(ans,cnt);
        }
    }
    cout << ans;
}