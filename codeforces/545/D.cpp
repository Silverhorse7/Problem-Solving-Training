#include "bits/stdc++.h"

using namespace std;
[[maybe_unused]] mt19937 mt(time(nullptr));

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;

    cin >> n;

    vector<int> a(n);

    for (auto &i: a)
        cin >> i;

    sort(a.begin(), a.end());

    int total_time = 0, x = 0;

    for (int i = 0; i < n; i++)
        if (a[i] >= total_time)
            x++, total_time += a[i];

    cout << x;
}