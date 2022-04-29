#include "bits/stdc++.h"

using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    map<string, int> m1, m2;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        m1[x]++;
    }
    
    int common = 0;
    for (int i = 0; i < m; i++) {
        string x;
        cin >> x;
        m2[x]++;
        if(m1[x])
        common++;
    }
    if (n - common + common % 2 > m - common)
        cout << "yes";
    else
        cout << "no";
}