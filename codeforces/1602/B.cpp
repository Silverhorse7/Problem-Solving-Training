#include <bits/stdc++.h>

using namespace std;
const int N = 2022;
int a[N], n, ID[N][N];
int mx_rounds;

void update() {
    map<int, int> mp;
    mx_rounds=0;
    while (true) {
        for (int i = 0; i < n; i++)ID[mx_rounds][i] = a[i];//2000
        for (int i = 0; i < n; i++)mp[a[i]]++;//2000
        bool flag = false;
        for (int i = 0; i < n; i++) {//2000
            if (a[i] != mp[a[i]])flag = true;
            a[i] = mp[a[i]];
        }
        mp.clear();//2000
        mx_rounds++;
        if (!flag)break;
        //2000*8000
    }
}

signed main() {
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    
    int t;
    cin >> t;
    while (t--) {
        memset(ID,0,sizeof ID);//2000*2000 = 4e6 operations
        cin >> n;
        for (int i = 0; i < n; i++)cin >> a[i];
        update();
        int Q;
        cin >> Q;
        while (Q--) {
            int x, k;
            cin >> x >> k;
            if (k >= mx_rounds)k = mx_rounds - 1;
            cout << ID[k][x - 1] << endl;
        }
    }
}