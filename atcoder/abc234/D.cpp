#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
int n, k, p[500000];

signed main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)cin >> p[i];
    for (int i = 0; i < n; i++) {
        os.insert(p[i]);
        if (i >= k - 1) cout << *(os.find_by_order(os.size() - k)) << endl;
    }
}