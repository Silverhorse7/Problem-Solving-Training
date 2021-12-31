    #include "bits/stdc++.h"

    using namespace std;

    int32_t main() {
        int n;
        cin >> n;
        map<int, int> frq;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        for (int i = 0; i < n; i++)cin >> b[i];
        for (int i = 0; i < n; i++)cin >> c[i];
        for (auto i: a)frq[i]++;
        long long cnt = 0;
        for(int i = 0 ; i <n;i++){
               // if(a[j]==b[c[i]-1])
                    cnt+=frq[b[c[i]-1]];
        }
        cout<<cnt;
    }