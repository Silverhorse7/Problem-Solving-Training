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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vector<pair<int, int>> point(3);
        for (int i = 0; i < 3; i++)cin >> point[i].first >> point[i].second;
        int df1 = b - a, df2 = d - c;
        if (((a || b) && point[2].first - point[1].first == 0) ||
            ((c || d) && point[2].second - point[1].second == 0) or
            ((point[0].first + df1 < point[1].first ||
              point[0].first + df1 > point[2].first ||
              point[0].second + df2 < point[1].second ||
              point[0].second + df2 > point[2].second)))
            cout << "No" << endl;
        else
            cout << "YES" << endl;
    }
}