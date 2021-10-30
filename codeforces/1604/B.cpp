#include <bits/stdc++.h>

using namespace std;
#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define T int T;cin>>T;while(T--)
#define ld long double
#define yes {cout<<"YES"<<endl;return;};
#define no {cout<<"NO"<<endl;return;};
void solve(){
    ll sz;
    cin >> sz;

    vector<ll> v(sz);
    for (auto &i : v)cin >> i;
    if (sz % 2 == 0) {
        yes;
    }
    for (int i = 1; i < sz; i++) {
        if (v[i - 1] >= v[i]) {
            yes;
        }
    }
    no;
}
signed main() {
    T {
        solve();
    }

    return 0;
}