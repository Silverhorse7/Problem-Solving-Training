#include "bits/stdc++.h"

using namespace std;

signed main() {
    int T;
    cin>>T;
    while(T--) {
        int a, b, c;
        cin >> a >> b;
        cout << min({a, b, (a + b) / 3}) << endl;
    }
}