#include "bits/stdc++.h"

using namespace std;
#define int long long

signed main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        bool flag = 0;
        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < s.size(); j++)
                if (s[i] == t[j])flag = 1;
        if (flag)
            cout << "YES";
        else
            cout << "no";
        cout << endl;
    }
}