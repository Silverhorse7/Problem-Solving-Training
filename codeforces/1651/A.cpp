#include "bits/stdc++.h"

using namespace std;

signed main() {
    int T;
    scanf("%d", &T);
    auto solve = []() {
        long long n;
        cin >> n;
        cout<<(1<<n)-1<<endl;
    };
    while (T--) {
        solve();
    }
}