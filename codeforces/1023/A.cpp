//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define Silver_is_better_than_Gold ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
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
#define ld long double
#define vb vector<bool>
#define no {cout<<"NO"<<endl;return ;}
#define yes {cout<<"YES"<<endl;return ;}
#define tests(x) for(int i =  1 ; i<=x;i++)
#define inp(v, n) for(int i = 0 ;  i<n;i++)cin>>v[i];
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
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

ll fastpow(ll base, ll power, ll M) {
    if (power == 1) return base;
    ll val = fastpow(base, power / 2, M);
    return (power % 2 == 0) ? (val * val) % M : (((val * val) % M) * base) % M;
}
// Computes the inverse of n modulo m.
// Precondition: n >= 0, m > 0 and gcd(n, m) == 1.
// The returned value satisfies 0 <= x < m (Inverse(0, 1) = 0).
// ACHTUNG: It must hold max(m, n) < 2**31 to avoid integer overflow.
ll Inverse(ll n, ll m) {
    n %= m;
    if (n <= 1) return n; // Handles properly (n = 0, m = 1).
    return m - ((m * Inverse(m, n) - 1) / n);
}

// Fast exponentiation modulo mod. Returns x**e modulo mod.
// Assumptions: 0 <= x < mod
//              mod < 2**31.
//              0 <= e < 2**63
ll pow(ll x, ll e, ll mod) {
    ll res = 1;
    for (; e >= 1; e >>= 1) {
        if (e & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

// Struct that computes x % mod faster than usual, if mod is always the same.
// It gives a x1.8 speed up over the % operator (with mod ~ 1e9 and x large).
// It is an implementation of the Barrett reduction, see
//    https://en.wikipedia.org/wiki/Barrett_reduction .
// If fast_mod is an instance of the class, then fast_mod(x) will return
// x % mod. There are no restrictions on the values of mod and x, provided
// that they fit in an unsigned long long (and mod != 0).
//
// ACHTUNG: The integer type __uint128_t must be available.
struct FastMod {
    unsigned long long mod;
    unsigned long long inv;

    FastMod(unsigned long long mod) : mod(mod), inv(-1ULL / mod) {}

    unsigned long long operator()(unsigned long long x) {
        unsigned long long q = (unsigned long long) ((__uint128_t(inv) * x) >> 64);
        unsigned long long r = x - q * mod;
        return r - mod * (r >= mod);
    }
};

//----------------------Code Starts Here-----------------------------//
const int N = 1e6 + 5, P1 = 31, P2 = 37, M = 1e9 + 7;
int pw1[N], pw2[N], inv1[N], inv2[N];

int mul(int a, int b) {
    a = ((a % M) + M) % M;
    b = ((b % M) + M) % M;
    return (a * 1LL * b) % M;
}

int add(int a, int b) {
    a = ((a % M) + M) % M;
    b = ((b % M) + M) % M;
    return (a + b) % M;
}

int fastPower(int base, int power) {
    if (!power) return 1;
    int ret = fastPower(base, power >> 1);
    ret = mul(ret, ret);
    if (power % 2) ret = mul(ret, base);
    return ret;
}

void pre() {
    pw1[0] = inv1[0] = pw2[0] = inv2[0] = 1;
    int mulInv1 = fastPower(P1, M - 2);
    int mulInv2 = fastPower(P2, M - 2);
    for (int i = 1; i < N; i++) {
        pw1[i] = mul(pw1[i - 1], P1);
        pw2[i] = mul(pw2[i - 1], P2);
        inv1[i] = mul(inv1[i - 1], mulInv1);
        inv2[i] = mul(inv2[i - 1], mulInv2);
    }
}

struct Hash {
    vector<pair<int, int>> prefixHash, suffixHash;

    Hash(string s) {
        if (s.size() == 0)return;
        prefixHash = vector<pair<int, int>>(s.size(), {0, 0});
        suffixHash = vector<pair<int, int>>(s.size(), {0, 0});
        for (int i = 0; i < s.size(); i++) {
            prefixHash[i].first = mul(s[i] - 'a' + 1, pw1[i]);
            prefixHash[i].second = mul(s[i] - 'a' + 1, pw2[i]);
            if (i)
                prefixHash[i] = {
                        add(prefixHash[i].first, prefixHash[i - 1].first),
                        add(prefixHash[i].second, prefixHash[i - 1].second)
                };
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            suffixHash[i].first = mul(s[i] - 'a' + 1, pw1[s.size() - i - 1]);
            suffixHash[i].second = mul(s[i] - 'a' + 1, pw2[s.size() - i - 1]);
            if (i == s.size() - 1)continue;
            suffixHash[i] = {
                    add(suffixHash[i].first, suffixHash[i + 1].first),
                    add(suffixHash[i].second, suffixHash[i + 1].second)
            };
        }
    }

    pair<int, int> getHashVal() {
        return prefixHash.back();
    }

    pair<int, int> getRangeHashVal(int l, int r) {
        return {
                mul(add(prefixHash[r].first, -(l ? prefixHash[l - 1].first : 0)), inv1[l]),
                mul(add(prefixHash[r].second, -(l ? prefixHash[l - 1].second : 0)), inv2[l])
        };
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if (n > m + 1) no;
    if (count(all(s), '*') == 0 and s != t) no;
    int pos = -1;
    for (int i = 0; i < n; i++)
        if (s[i] == '*')pos = i;
    string y = "";
    for (int i = 0; i < pos; i++)
        y += s[i];
    Hash Y(y);
    Hash TT(t);
    bool f1 = y.empty(), f2 = 0;
    if(y.size())
    for (auto i: TT.prefixHash)
        if (i == Y.getHashVal())f1 = 1;
    y.clear();
    for (int j = n - 1; j > pos; j--)y += s[j];
    Hash F(y);
    f2 = y.empty();
    if(y.size())
    for (auto i: TT.suffixHash)
        if (i == F.getHashVal())f2 = 1;
    if (f1 and f2) yes;
    no;
}

signed main() {
    pre();
    solve();
}