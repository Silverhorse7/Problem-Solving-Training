#include<bits/stdc++.h>

using namespace std;

#define ll long long

bool chk(string s) {
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] == s[i + 1])return 0;
    return 1;
}

void TaskA() {
    int n;
    cin >> n;
    string s = "";
    int f = n;
    while (n > 0) {
        if (s.size() % 2 == 0) {
            if (n >= 2)
                s += '2', n -= 2;
            else
                s += '1', n -= 1;
        } else
            s += '1', n -= 1;
    }
    if (chk(s)) {
        cout << s << endl;
        return;
    }
    s = "";
    n = f;
    while (n > 0) {
        if (s.size() % 2 == 0) {
            if (n >= 1)
                s += '1', n -= 1;
            else
                s += '2', n -= 2;
        } else
            s += '2', n -= 2;
    }
    cout << s << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--)TaskA();
}