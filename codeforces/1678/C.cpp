#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <random>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
using namespace std;
#define ll long long
#define Silver_is_better_than_Gold \
    ios_base::sync_with_stdio(0);  \
    cin.tie(0);                    \
    cout.tie(0);
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
#define endl '\n'
#define test cout << " We Droped up Here Boss _________________ " << endl
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define no                    \
    {                         \
        cout << "NO" << endl; \
    }
#define yes                    \
    {                          \
        cout << "YES" << endl; \
    }
const int mod = 1e9 + 7;
#define sz(x) ((int)(x).size())
#define dups(divs) divs.erase(unique(divs.begin(), divs.end()), divs.end());
#define sum(v) accumulate(v.begin(), v.end(), 0ll)
#define T       \
    int XXX;    \
    cin >> XXX; \
    while (XXX--)
#define F first
#define SS second
#define ld long double
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

template <class A>
istream &operator>>(istream &cin, pair<A, A> p)
{
    return cin >> p.first >> p.second;
}

template <class A>
istream &operator>>(istream &cin, vector<A> &p)
{
    for (int i = 0; i < sz(p) - 1; i++)
        cin >> p[i];
    return cin >> p.back();
}

template <class A>
ostream &operator<<(ostream &cout, pair<A, A> const &v)
{
    return cout << v.first << ' ' << v.second << endl;
}

template <class A>
ostream &operator<<(ostream &cout, vector<A> const &v)
{
    for (auto ele : v)
    {
        cout << ele << " ";
    }
    cout << endl;
    return cout;
}

ll fastpow(ll base, ll power, ll M)
{
    if (power == 1)
        return base;
    ll val = fastpow(base, power / 2, M);
    return (power % 2 == 0) ? (val * val) % M : (((val * val) % M) * base) % M;
}

///////////////////////////////////////////////////////////////////////////]
int32_t main()
{
    Silver_is_better_than_Gold int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        vector<vector<int>> b(n), c(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (v[i] > v[j])
                    b[i].push_back(j);
            }
        }
        for (int i = 0; i < n; i++)
            sort(all(b[i]));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (v[j] < v[i])
                {
                    c[i].push_back(j);
                }
            }
        }
        long long cnt = 0;
        auto from_right = [&](int &j, int &x)
        {
            int l = 0, r = b[j].size() - 1;
            int ans = b[j].size();
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (x < b[j][mid])
                    ans = mid, r = mid - 1;
                else
                    l = mid + 1;
            }
            return b[j].size() - ans;
        };
        auto from_left = [&](int &j, int &x)
        {
            int l = 0, r = c[j].size() - 1;
            int ans = -1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (c[j][mid] < x)
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            return ans + 1;
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                cnt += from_right(i, j) * from_left(j, i);
            }
        }
        cout << cnt << endl;
    }
}