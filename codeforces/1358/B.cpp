#include "bits/stdc++.h"

using namespace std;
#define int long long

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i: v)
            cin >> i;
        sort(v.begin(), v.end());
        int cnt = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 >= v[i]) {
                cnt += i + 1;
                break;
            }
        }
        cout<<cnt<<endl;
    }
}