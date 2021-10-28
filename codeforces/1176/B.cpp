#include<bits/stdc++.h>

using namespace std;

int t, n;
int cnt[3];

int main(){
    cin >> t;
    for(int tc = 0; tc < t; ++tc){
        memset(cnt, 0, sizeof cnt);
        cin >> n;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            ++cnt[x % 3];
        }
    	
    	int res = cnt[0];
        int mn = min(cnt[1], cnt[2]);
        res += mn;
        cnt[1] -= mn, cnt[2] -= mn;
        res += (cnt[1] + cnt[2]) / 3;
        cout << res << endl;
    }
    return 0;
}