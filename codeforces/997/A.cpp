#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<int> groups;
    for (int i = 0; i < n; i++) {
        int flag = -1;
        while (i < n and s[i] == '0') {
            if (flag == -1)
                flag = i;
            i++;
        }
        if (flag != -1)
            groups.push_back(flag);
    }
    cout << (groups.empty() ? 0 : (groups.size() - 1) * min(x, y) + y) << endl;
}