//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
using namespace std;
#define ll long long
#define Silver_is_better_than_Gold ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pb push_back
#define endl       '\n'
#define return0 return 0
#define Endl endl
#define ull unsigned long long
#define elif else if
#define test   cout<<" We Droped up Here Boss _________________ "<<endl
#define allout(v) for(auto ele : v){cout<<ele<<" ";}cout<<endl
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define txt freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define ld long D
#define vb vector<bool>
#define no {cout<<"NO"<<endl;return ;}
#define yes {cout<<"YES"<<endl;return ;}
#define tests(x) for(int i =  1 ; i<=x;i++)
#define in(v, n) for(int i = 0 ;  i<n;i++)cin>>i;
#define outp(v) for(auto ele : v){        cout << ele.first << " " << ele.second << " ";}cout<<endl
const ll mod = 1e9 + 7;
#define inti int i
#define sz(x) ((int) (x).size())
#define dups(divs)     divs.erase(unique(divs.begin(), divs.end()), divs.end());
#define fo(i, v, b) for(int i = v ; i<=b;i++)
#define outq(q)     queue<int>qq = q;while (qq.size()) { cout << qq.front() << " "; qq.pop();};
#define sttk(x) static_cast<ll>(x)
#define re register
#define intj int j
#define debug cout<<"Output is  :  ";
#define debug2 cout<<"End of the output______________________"<<endl;
#define sum(v) accumulate(v.begin(),v.end(),0ll)
#define range(i, n) for(int i = 0 ; i <n;i++)
#define point pair<int,int>
#define T int XXX;cin>>XXX;while(XXX--)
#define F first
#define S second
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

template<class A>
istream &operator>>(istream &cin, vector<A> &p) {
    for (int i = 0; i < sz(p) - 1; i++)
        cin >> p[i];
    return cin >> p.back();
}

template<class A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
    allout(v);
    return cout;
}

ll fastpow(ll base, ll power, ll M) {
    if (power == 1) return base;
    ll val = fastpow(base, power / 2, M);
    return (power % 2 == 0) ? (val * val) % M : (((val * val) % M) * base) % M;
}

//----------------------Code Starts Here-----------------------------//
struct dsu {
    vector<int> par;
    vector<int> sz;

    dsu(int N) {
        par.resize(N);
        sz.resize(N, 1);
        iota(all(par), 0);
    }

    int get_par(int x) {
        if (par[x] == x)return x;
        return par[x] = get_par(par[x]);
    }

    void unite(int a, int b) {
        a = get_par(a);
        b = get_par(b);
        if (a == b)return;
        if (sz[a] > sz[b]) {
            sz[a] += sz[b];
            par[b] = a;
        } else {
            sz[b] += sz[a];
            par[a] = b;
        }
    }
};

void solve() {
    int n;
    cin >> n;
    dsu D(n+333);
    vector<string> v(n);
    vector<vector<int>> adj(1000);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto j: s)
            adj[j - 'a'].push_back(i);
    }
    for (int i = 0; i < 30; i++) {
        for (int j = 1; j < adj[i].size(); j++)
            D.unite(adj[i][j - 1], adj[i][j]);
    }
    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(D.get_par(i));
    cout << st.size() << endl;
}

signed main() {
    solve();
}