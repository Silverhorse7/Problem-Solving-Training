#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5+5;

void testCase() {
    
    int n, x, k, ans = INT_MAX;

    cin >> n >> k;

    vector<int> v[N];

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        cin >> x;

        while (x > 0) {
            v[x].push_back(cnt);
            x/=2;
            cnt++;
            if (x == 0)
                v[x].push_back(cnt);
        }
    }

    for (int i = 0; i < N; i++) {
        if (v[i].size() < k)
            continue;
        sort(v[i].begin(), v[i].end());
        ans = min(ans, accumulate(v[i].begin(), v[i].begin()+k, 0));
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases = 1;

   // cin >> testCases;

    while (testCases--)
        testCase();

    return 0;
}