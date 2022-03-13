#include "bits/stdc++.h"

using namespace std;
#define ll long long

ll count(ll n) {
    ll cnt = 0;
    for (ll k = 2;; ++k) {
        ll k3 = k * k * k;
        if (k3 > n) break;
        cnt += n / k3;
    }

    return cnt;
}

int main() {
    ll m;
    cin >> m;
    ll lo = 1, hi = 1e17;
    ll ans = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll cnt = count(mid);
        if (cnt >= m) {
            if (cnt == m) ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
}