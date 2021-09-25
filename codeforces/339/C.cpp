#include<bits/stdc++.h>

using namespace std;
vector<int> W(101);
vector<int> v;
int m;

bool dfs(int x, int y, int k) {
    if (k > m)return 1;
    int f = 0;
    for (int i = 1; i <= 10; i++) {
        if (W[i] && y != i) {
            if (x >= 0 && x - i < 0) {
                f = dfs(x - i, i, k + 1);
            } else if (x < 0 && x + i > 0) {
                f = dfs(x + i, i, k + 1);
            }
        }
        if (f) {
            v.push_back(i);
            return 1;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s>>m;
    for (int i = 0; i<  s.size(); i++) {
        if (s[i] == '1')W[i + 1] = 1;
    }
    if (dfs(0, 0, 1)) {
        reverse(v.begin(), v.end());
        cout << "YES" << endl;
        for (auto a : v)
            cout << a << ' ';

    } else {
        cout << "NO";
    }
    return 0;
}
