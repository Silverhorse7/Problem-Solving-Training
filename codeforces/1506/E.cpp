#include<bits/stdc++.h>

using namespace std;
#define allout(v) {for(auto i : v)cout<<i<<' ';cout<<endl;}

vector<int> Min(vector<int> Q) {
    set<int> pq;
    map<int, int> mp;
    for (auto i: Q)
        mp[i]++;
    for (int i = 1; i <= Q.size(); i++) {
        if (mp[i] == 0) {
            pq.insert(i);
        }
    }
    vector<int> ans(Q.size());
    ans[0] = Q[0];
    for (int i = 1; i < ans.size(); i++) {
        if (Q[i] == Q[i - 1]) {
            ans[i] = *pq.begin();
            pq.erase(pq.begin());
        } else
            ans[i] = Q[i];
    }
    return ans;
}

vector<int> Max(vector<int> Q) {
    //just inputting S,ind,val
    int n = Q.size();
    vector<int> ans(n);
    set<int> S;
    map<int, int> Data;
    vector<int> ind, val;
    for (int i = 0; i < Q.size(); i++) {
        int xa = Data.size();
        Data[Q[i]] = 1;
        if (Data.size() != xa) {
            ind.push_back(i);
            val.push_back(Q[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (Data[i] == 0) {
            S.insert(i);
        }
    }
    ind.push_back(n);
    val.push_back(n);
    for (int i = 0; i < ind.size() - 1; i++) {
        ans[ind[i]] = val[i];
    }
    //input done 
    //shit starts here : 
    for (int i = 0; i + 1 < ind.size(); i++) {
        for (int j = ind[i] + 1; j < ind[i + 1] && j < n; j++) {
            auto s = S.lower_bound(Q[j]);
            if (s == S.end()) {
                ans[j] = *S.rbegin();
                S.erase(*S.rbegin());
                continue;
            }
            s--;
            assert(s != S.end());
            ans[j] = *s;
            S.erase(s);
        }
    }
    return ans;
}

signed main() {
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> Q(n);
        for (auto &i: Q)
            cin >> i;
        allout(Min(Q));
        allout(Max(Q));
    }
}