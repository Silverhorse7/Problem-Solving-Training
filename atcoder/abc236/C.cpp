#include<bits/stdc++.h>

using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &i: s)
        cin >> i;
    set<string> ms;
    for (int i = 0; i < m; i++) {
        string x;
        cin >> x;
        ms.insert(x);
    }
    for (int i = 0; i < n; i++) {
        if (ms.count(s[i])) {
            cout << "Yes";
        } else
            cout << "No";
        cout << endl;
    }
}