#include<bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    set<int> st[1000];
    for (int i = 0; i < s1.size(); i++)
        st[s1[i]].insert(i);
    for (auto ele : s2)
        if (st[ele].empty())return cout << -1, 0;
    int y = -1;
    int cnt = 0;
    for (char i : s2) {
        auto x = st[i].upper_bound(y);
        if (x == st[i].end()) {
            cnt++;
            y = *st[i].begin();

        }
        else{
            y=*x;
        }
    }
    cout<<cnt+1<<endl;
}