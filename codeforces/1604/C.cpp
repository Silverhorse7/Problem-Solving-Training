#include <bits/stdc++.h>

#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define T int T;cin>>T;while(T--)
#define ld long double
void solve()
{
    int n; cin >> n;
    list<int> Total;
    for(int i = 0 ;  i<n;i++)
    {
        int ff; cin >> ff;
        Total.push_back(ff);
    }


    while (Total.size())
    {
        bool fine  = false;
        int index = Total.size();
        auto Iterator = Total.end();
        --Iterator;
        for (; Iterator != Total.begin(); --Iterator, --index) {
            if (!(*Iterator % (index + 1))) continue;
            fine = true;
            Total.erase(Iterator);
            break;
        };

        if (fine || !(*Iterator % (index + 1))) {}
        else {
            fine = true;
            Total.erase(Iterator);
        }
        if (fine)
            continue;
        break;
    }
    if (!Total.size()) cout << "YES\n";
    else cout << "NO\n";

}

int main()
{
    int t; cin >> t;
    while (t--) solve();
    return 0;
}