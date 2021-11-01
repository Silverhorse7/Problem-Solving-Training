#include <bits/stdc++.h>

using namespace std;
#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define T int T;cin>>T;while(T--)
#define ld long double
#define yes {cout<<"YES"<<endl;return;};
#define no {cout<<"NO"<<endl;return;};

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char a[3] = {'R', 'G', 'B'};
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1] ) {
            for (char j : a) {
                if (j != s[i - 1] and j!=s[i+1]) {
                    s[i] = j;
                    break;
                }
            }
            cnt++;
        }
    }
    cout<<cnt<<endl<<s;
}