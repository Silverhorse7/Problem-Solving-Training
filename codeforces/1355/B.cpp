#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 69;
int a[N];
int n;

signed main() {
    ios_base::sync_with_stdio();
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)scanf("%d", &a[i]);
        sort(a, a + n);
        int ans = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++, cnt++) {
            if (cnt == a[i]) {
                cnt=0;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}