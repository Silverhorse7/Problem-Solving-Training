#include <bits/stdc++.h>

#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define T int T;cin>>T;while(T--)
#define ld long double
int a[(const int) (2e5 + 66)];

signed main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<int> costs;
    for (int i = 0; i < n; i++)cin >> a[i];
    int sum = 0;
    vector<int> p1;
    int ev = 0, od = 0;
    for (int i = 0; i < n; i++) {
        if (ev == od and ev != 0) {
            p1.push_back(i);
            ev = od = 0;
        }
        if (a[i] % 2 == 0)ev++;
        else
            od++;
    }
    for (int i : p1) {
        costs.push_back(abs(a[i] - a[i - 1]));
    }
    // for(auto i : p1)cout<<i<<' ';
    sort(costs.begin(), costs.end());
    for (auto i : costs)
        if (m >= i) {
            m -= i;
            sum++;
        }
    cout << sum << endl;
}