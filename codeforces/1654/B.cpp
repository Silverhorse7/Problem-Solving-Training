#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        map<char, int> mp;
        for (auto i: s)
            mp[i]++;
        for (char &i: s) {
            if (mp[i] == 1)break;
            mp[i]--;
            i = -1;
        }
        for (char i: s)
            if (i != -1)cout << i;
        cout << endl;
    }
}