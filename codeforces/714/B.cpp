#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 69;
int a[N];
map<int, int> mp;
int n;

signed main() {
    ios_base::sync_with_stdio();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int sm = 0;
    for (auto &a : mp)sm += a.first;
    if ((mp.size() == 2) or mp.size()==1) {
        cout << "YES";return 0;
    }
    else if(mp.size()==3){
        vector<int>v;
        for(auto &b : mp)v.push_back(b.first);
        int x =v[1]-v[0];
        x-=(v[2]-v[1]);
        if(x==0){cout<<"YES"; return 0;}
    }
    cout<<"NO";
}