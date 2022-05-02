#include "bits/stdc++.h"

using namespace std;

signed main() {
    int T;
    cin >> T;
    map<string, int> mp;
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            if (i == j)continue;
            string s = "";
            s += i;
            s += j;
            mp[s] = mp.size() + 1;
        }
    }
    while (T--) {
        string f;
        cin >> f;
        cout << mp[f] << endl;
    }
}