#include "bits/stdc++.h"

using namespace std;
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    string s;
    cin >> s;
    vector<int> alph(26, 0);
    for (int i = 0; i < s.length(); ++i) {
        ++alph[s[i] - 'a'];
    }
    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        if (alph[i])
            ++cnt;
    }
    if (cnt == 4) {
        return cout<<"Yes",0;
    } else if (cnt == 3) {
        int ans = false;
        for (int i = 0; i < 26; ++i) {
            if (alph[i] > 1)
                ans = true;
        }
        if (ans) {
            return cout<<"Yes",0;
        } else {
            return cout<<"No",0;
        }
    } else if (cnt == 2) {
        int cnt2 = 0;
        for (int i = 0; i < 26; ++i) {
            if (alph[i] > 1)
                ++cnt2;
        }
        if (cnt2 >= 2) {
            return cout<<"Yes",0;
        } else {
            return cout<<"No",0;
        }
    } else {
        return cout<<"No",0;
    }
}
