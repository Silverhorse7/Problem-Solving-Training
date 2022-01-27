#include<bits/stdc++.h>

using namespace std;
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

signed main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> p(n);
    for (auto &i: p)
        scanf("%d", &i);
    ordered_set os;
    for (int i = 0; i < k; i++)
        os.insert(p[i]);
    cout << *(os.find_by_order(os.size()-k)) << endl;
    for (int i = k; i < n; i++) {
        os.insert(p[i]);
        cout << *(os.find_by_order(os.size()-k)) << endl;
    }
}