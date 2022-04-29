#include "bits/stdc++.h"

using namespace std;

signed main() {
    int n;
#define int double
    int pocket;
    cin >> n >> pocket;
    vector<int> w(n);
    for (auto &i: w)
        cin >> i;
    int cnt = 0;
    int x[2] = {};
    int turn = 0;
    for (int i = 0; i < n; i++) {
        cnt += ceil(w[i] / pocket);
    }
    cout << (long long) floor((cnt + 1) / 2.0) << endl;
}