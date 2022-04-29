#include "bits/stdc++.h"

using namespace std;
#define int long long

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        long long ans = 0;
        for (int i = 1; i <= n / 2; i++)
            ans += i*i;
        cout<<ans*8<<endl;
    }
}