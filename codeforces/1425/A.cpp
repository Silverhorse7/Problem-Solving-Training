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
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

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
vector<int> dp(1e5, -1);

ll call(ll n) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    dp[n] = 1 + (n - 1) - call(n - 1);
    if (n % 2 == 0) {
        dp[n] = max(dp[n], n - call(n / 2));
    }
    return dp[n];
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    T {
        ll n;
        cin >> n;
        ll a[2] = {0, 0};
        int turn = 0;
        while (n) {
            if (n < 1e5) {
                a[turn] += call(n);
                a[turn ^ 1] += n - call(n);
                n = 0;
            } else if (n & 1LL) {
                a[turn]++;
                n--;
            } else {
                if ((n / 2) & 1LL) {
                    a[turn] += n / 2;
                    n /= 2;
                } else {
                    a[turn]++;
                    n--;
                }
            }
            turn ^= 1;
        }
        cout << a[0] << '\n';
    }
    return 0;
}