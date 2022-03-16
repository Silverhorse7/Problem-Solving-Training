#include "bits/stdc++.h"

using namespace std;

signed main() {
    int a, b;
    cin >> a >> b;
    long long ans = 0;
    while ((ans+1) * (ans + 2) / 2 <= a + b) ans++;

    vector<int> qa, qb;
    for (int i = ans; i >= 1; i--) {
        if (a >= i) {
            a -= i;
            qa.push_back(i);
        } else
            qb.push_back(i);
    }
    cout << qa.size() << endl;
    for (int i : qa)
        cout << i << " ";
    cout << endl;
    cout << qb.size() << endl;
    for (int i : qb)
        cout << i << " ";
}