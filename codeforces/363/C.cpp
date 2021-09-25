#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    string ans = "";
    vector<string> total;
    int n =s.size();
    for(int i = n-1 ; i >=0;i--){
        string x="";
        x+=s[i];
        while(i>0 and s[i]==s[i-1]){
            x+=s[i-1];
            i--;
        }
        total.push_back((x.size()>=2 ? string(2,x[0]) : x));
    }
    reverse(total.begin(), total.end());
    ans += total[0];
    for (int i = 1; i < total.size(); i++) {
        if (total[i].size() == 2) {
            if (total[i - 1].size() == 2) {
                total[i] = total[i][0];
            }
        }
        ans += total[i];
    }
    cout << ans;
}