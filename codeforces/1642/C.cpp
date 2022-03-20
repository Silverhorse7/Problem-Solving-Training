#include <iostream>
#include<queue>
#include "algorithm"
#include "map"

using namespace std;
#define int long long
const int N = 2e5 + 55;
int a[N];

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        map<int, vector<int>> mp;
        for (int i = n - 1; i >= 0; i--)
            mp[a[i]].push_back(i);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1)continue;
            if (!mp[a[i] * x].empty()) {
                a[mp[a[i] * x].back()] = -1;
                mp[a[i] * x].pop_back();
            } else {
                cnt++;
            }
            a[mp[a[i]].back()] = -1;
            mp[a[i]].pop_back();
        }
        cout << cnt << endl;
    }
}