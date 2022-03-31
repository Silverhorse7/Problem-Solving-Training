

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    map<pair<int, int>, int> memo;
    vector<int> v(N + 1);
    auto Query = [&](int l, int r) {
        if (memo.find({l, r}) != memo.end())return memo[{l, r}];
        cout << "? " << l << ' ' << r << endl;
        int x;
        cin >> x;
        return memo[{l, r}] = x;
    };
    for (int j = 2; j <= N; j++)
        Query(1, j);
    for (int i = 3; i <= N; i++)
        v[i] = Query(1, i) - Query(1, i - 1);
    v[2] = Query(2, 3) - v[3];
    v[1] = Query(1, 2) - v[2];
    cout << "! ";
    for (int i = 1; i <= N; i++)cout << v[i] << ' ';

}