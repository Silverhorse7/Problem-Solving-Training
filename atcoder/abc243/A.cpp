#include<bits/stdc++.h>

using namespace std;

signed main() {
    int v, a, b, c;
    //a,b,c
    cin >> v >> a >> b >> c;
    int roles = 0;
    vector<pair<int, char>> e = {{a, 'F'},
                                 {b, 'M'},
                                 {c, 'T'}};
    while (v >= 0) {
        v -= e[roles % 3].first;
        if (v < 0) {
            cout << e[roles % 3].second << endl;
        }
        roles++;
    }
}