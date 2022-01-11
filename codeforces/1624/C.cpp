#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
#define int long long
#define sz(v) (int)v.size()
signed main() {//
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n+44);
        for (int i = 0; i < n; i++)cin >> v[i];
        auto get_all = [&](int x) -> vector<int> {
            vector<int> y;
            while (x) {
                if(x<=n)
                    y.push_back(x);
                x /= 2;
            }
            sort(y.begin(), y.end());
            return y;
        };
        vector<vector<int>> all;
        sort(v.begin(), v.begin()+n);
        for (int i = 0; i < n; i++) {
            all.push_back(get_all(v[i]));
        }
        sort(all.begin(), all.end());
        map<int, int> frq;
        for (const auto& i: all)
            for (auto j: i) {
                frq[j]++;
            }
        multiset<int> ms;
        auto cmp = [&](int &x, int &y) -> bool {
            if (frq[x] > frq[y])return true;
            if (frq[x] < frq[y])return false;
            return true;
        };
        auto cmp1 = [&](vector<int> &v1, vector<int> &v2) -> bool {
            if (sz(v1) > sz(v2))return 1;
            if (sz(v1) < sz(v2))return 0;
            for (int i = 0; i <sz(v1); i++) {
                if (frq[v1[i]] > frq[v2[i]])return true;
                if (frq[v1[i]] < frq[v2[i]])
                    return false;
            }
            return true;
        };
        for (auto &i: all) {
            sort(i.rbegin(), i.rend(), cmp);
        }
        sort(all.begin(), all.end(), cmp1);
        for (auto &i: all) {
            for (auto j: i) {
                if (j <= n && ms.find(j) == ms.end()) {
                    ms.insert(j);
                    break;
                }
            }
        }
        if (ms.size() == n)cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }//
}