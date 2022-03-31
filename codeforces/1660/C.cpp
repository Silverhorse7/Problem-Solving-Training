

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
using namespace std;
#define ll long long
//----------------------Code Starts Here-----------------------------//
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        string s;
        int n;
        cin >> s;
        n = s.size();
        s = "O" + s;
        set<ll> st[26+333];
        vector<int> Memo(n + 33), forwardCo(n + 33);
        for (int i = 1; i <= n; ++i) {
            st[s[i] - 'a'].insert(i);
            Memo[i] = forwardCo[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            forwardCo[i] = max(forwardCo[i - 1], Memo[i]);
            auto it = st[s[i] - 'a'].upper_bound(i);
            if (!(it == st[s[i] - 'a'].end())) {
                int j = *it;
                Memo[j] = max(Memo[j], forwardCo[i - 1] + 1);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans = max(ans, Memo[i]);
        cout << n - (ans * 2) << "\n";
    }
}