#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include <random>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;
#define ll long long
#define Silver_is_better_than_Gold ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pb push_back
#define endl '\n'
#define test   cout<<" We Droped up Here Boss _________________ "<<endl
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define no {cout<<"NO"<<endl;return;}
#define yes {cout<<"YES"<<endl;return;}
const int mod = 1e9 + 7;
#define sz(x) ((int) (x).size())
#define dups(divs)     divs.erase(unique(divs.begin(), divs.end()), divs.end());
#define sum(v) accumulate(v.begin(),v.end(),0ll)
#define T int XXX;cin>>XXX;while(XXX--)
#define F first
#define SS second
#define ld long double
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

template<class A>
istream &operator>>(istream &cin, vector<A> &p) {
    for (int i = 0; i < sz(p) - 1; i++)
        cin >> p[i];
    return cin >> p.back();
}

template<class A>
ostream &operator<<(ostream &cout, pair<A, A> const &v) {
    return cout << v.first << ' ' << v.second << endl;
}

template<class A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
    for (auto ele: v) { cout << ele << " "; }
    cout << endl;
    return cout;
}

ll fastpow(ll base, ll power, ll M) {
    if (power == 1) return base;
    ll val = fastpow(base, power / 2, M);
    return (power % 2 == 0) ? (val * val) % M : (((val * val) % M) * base) % M;
}

#define int long long

signed main() {
    Silver_is_better_than_Gold;
    auto solve = []() {
        int n;
        cin >> n;
        vi v(n);
        cin >> v;
        int x = *max_element(all(v));
        multiset<int> vis;
        for (int i = 0; i < n; i++)
            vis.insert(v[i]);
        for (int i = 1; i <= x; i++)
            if (x % i == 0) {
                vis.erase(vis.find(i));
            }
        cout << x << ' ' << *vis.rbegin() << endl;
    };
    solve();
}