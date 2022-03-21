#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i: v)
            cin >> i;
        sort(v.rbegin(), v.rend());
        cout<<v[0]+v[1]<<endl;
    }
}