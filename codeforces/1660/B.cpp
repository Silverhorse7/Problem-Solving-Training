

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
using namespace std;
//----------------------Code Starts Here-----------------------------//
const int N = 2e5 + 1;
int p[N];

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i: v)
            cin >> i;
        sort(v.begin(), v.end());
        if (n == 1 and v[0] >= 2) {
            cout << "NO" << endl;
            continue;
        }
        if (n == 1) {
            cout << "YES" << endl;
            continue;
        }
        cout<<(v[n-1]-v[n-2] <=1 ? "YES" :"NO")<<endl;
    }
}