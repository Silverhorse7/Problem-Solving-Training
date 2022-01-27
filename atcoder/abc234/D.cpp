#include<bits/stdc++.h>
#define j int
#define us using namespace
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
us __gnu_pbds;
us std;
tree<j, null_type, less<j>, rb_tree_tag, tree_order_statistics_node_update> os;
j n, k, i, x;
main() {cin >> n >> k;while (i < n) {cin >> x;os.insert(x);if (i++ >= k - 1) cout << *(os.find_by_order(os.size() - k)) << endl;}}