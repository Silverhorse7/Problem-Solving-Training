
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define no {cout<<"NO"<<endl;}
#define yes {cout<<"YES"<<endl;}
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
const int N = 2e4 + 5;
#define int long long

signed main() {
    Silver_is_better_than_Gold
    auto solve = []() {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int g = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                ++g;
            if (t[i] == 'a')
                ++g;
        }
        if (g % 2) {
            return cout << -1, 0;
        }
        int A = 0, B = 0;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i])
                continue;
            if (s[i] == 'a') {
                A++;
                a.pb(i + 1);
            }
            if (s[i] == 'b') {
                b.pb(i + 1);
                B++;
            }
        }
        int ops = (B / 2) + (A / 2);
        if (A % 2)
            ops += 2;
        cout << ops << endl;
        for (int i = 0; i + 1 < B; i += 2) {
            cout << b[i] << ' ' << b[i + 1] << endl;
        }
        for (int i = 0; i + 1 < A; i += 2) {
            cout << a[i] << ' ' << a[i + 1] << endl;
        }
        if (A % 2) {
            cout << b.back() << ' ' << b.back() << endl;
            cout << a.back() << ' ' << b.back() << endl;
        }
        return 0;
    };
    solve();
}