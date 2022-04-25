#include "bits/stdc++.h"

using namespace std;


signed main() {
    int Q;
    cin >> Q;
    map<int, int> mp1;
    map<int, set<int>,greater<>> mp2;
    int idx = 1;
    while (Q--) {
        int q;
        cin >> q;
        if (q == 1) {
            int x;
            cin >> x;
            mp1[idx] = x;
            mp2[x].insert(idx);
            idx++;
        }
        if (q == 2) {
            cout << mp1.begin()->first << ' ';
            mp2[mp1.begin()->second].erase(mp1.begin()->first);
            if (mp2[mp1.begin()->second].size() == 0)
                mp2.erase(mp1.begin()->second);
            mp1.erase(mp1.begin()->first);
        }
        if (q == 3) {
            cout << *mp2.begin()->second.begin() << ' ';
            mp1.erase(*mp2.begin()->second.begin());
            mp2.begin()->second.erase(*mp2.begin()->second.begin());
            if (mp2.begin()->second.size() == 0)
                mp2.erase(mp2.begin());
        }
    }
}