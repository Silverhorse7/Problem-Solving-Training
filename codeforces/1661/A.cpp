    #include<bits/stdc++.h>

    using namespace std;
#define int long long
    signed main() {
        int T;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            vector<int> a(n), b(n);
            for (auto &i: a)cin >> i;
            for (auto &i: b)cin >> i;
            for (int i = 0; i < n; i++)
                if (b[i] > a[i])swap(b[i], a[i]);
            int cnt = 0;
            for(int i =1;i<n;i++)cnt+=abs(a[i]-a[i-1]);
            for(int i =1;i<n;i++)cnt+=abs(b[i]-b[i-1]);
            cout<<cnt<<endl;
        }
    }