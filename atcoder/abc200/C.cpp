//  C - Ringo's Favorite Numbers 2

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v)
        cin >> i;
    map<int, int> mod;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += mod[v[i]%200];
        mod[v[i]%200] += 1;
    }
    cout << cnt;
}
