#include <bits/stdc++.h>

#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define T int T;cin>>T;while(T--)
#define ld long double

ld dist(pair<ld, ld> a, pair<ld, ld> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

bool cmp(pair<ld, ld> &a, pair<ld, ld> &b) {
    if (a.first == 0) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

signed main() {
    fast;
    ll n;
    cin >> n;
    T {
        ll x, y;
        cin >> x >> y;
        ll ans = ((((((x - 1) * n + y) + 1))/2));
        if ((x + y) % 2 == 0) {
            //first sum
        } else {
            ans+=((n*n+1)/2);
        }
        cout<<ans<<endl;
    }
}