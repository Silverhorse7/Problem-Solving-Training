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
    T {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        while (true) {
            bool flag = 0 ;
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == 'A') {
                    if (s[i + 1] == 'P') {
                        s[i+1]='A';
                        i++;
                        flag=1;
                    }
                }
            }
            ans++;
            if(!flag)break;
        }
        cout<<ans-1<<endl;
    }
}