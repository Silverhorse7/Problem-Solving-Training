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
#define allout(v) for(auto Ele : v){cout<<Ele<<" ";}cout<<endl
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
#define outp(v) for(auto Ele : v){        cout << Ele.first << " " << Ele.second << " ";}cout<<endl
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
#define int long long
const int N = 3e5 + 55;
pair<int, int> tree[4 * N];
int a[N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = make_pair(a[tl], tl);
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v] = {val, pos};
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, val);
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }
}

pair<int, int> query(int v, int tl, int tr, const int l, const int r) {
    if (r < tl || l > tr)
        return {INT_MAX, INT_MAX};
    if (tl >= l && tr <= r) {
        return tree[v];
    }
    int mid = (tl + tr) / 2;
    return min(query(2 * v, tl, mid, l, r), query(2 * v + 1, mid + 1, tr, l, r));
}

signed main() {
    // Silver_is_better_than_Gold
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        build(1, 0, n - 1);
        int Q;
        cin >> Q;
        while (Q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            vector<pair<int, int>> Arr(50);
            int Idx = 0;
            while (Idx < 40 and Idx <= (r - l)) {
                Arr[Idx] = query(1, 0, n - 1, l, r);
                update(1, 0, n - 1, Arr[Idx].second, 1e16);
                Idx++;
            }
            int ans = 1e17;
            for (int i = 0; i < Idx; i++) {
                for (int j = i + 1; j < Idx; j++) {
                    ans = min(ans, Arr[i].first | Arr[j].first);
                }
                update(1, 0, n - 1, Arr[i].second, Arr[i].first);
            }
            cout << ans << endl;
        }
    }
}