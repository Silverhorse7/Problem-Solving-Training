#include "bits/stdc++.h"
using namespace std;
#define all(s) s.begin(),s.end()
int job_done(int n, string s1,string s2) {
    int p1 = 0;
    int cnt = 0;
    string carry = "";
    while (p1 < n )
    {
        //  cout<<p1<<endl;
        if (!carry.empty()) {
            if (s1[p1] == '0' or s2[p1] == '0') {
                cnt += 2;
                p1++;
                carry.clear();
            } else {
                p1++;
            }
        }
        else if ((s1[p1] == '1' and s2[p1] == '0') or (s2[p1] == '1' and s1[p1] == '0')) {
            cnt += 2;
            p1++;
        }
        else if (s1[p1] == '0' and s2[p1] == '0') {
            if(p1+1 < n and (s1[p1+1]=='1' and s2[p1+1]=='1')){
                cnt+=2;
                p1+=2;
            }
            else {
                cnt += 1;
                p1++;
            }
        }
        else if (s1[p1] == '1' and s2[p1] == '1') {
            carry += 1;
        }
    }
    return cnt;
}
void C(){
    int n;
    cin>>n;
    string s1,s2;cin>>s1>>s2;
    int ans = job_done(n,s1,s2);
    cout<<ans<<endl;
}
signed main() {
    int t;
    cin>>t;
    while(t--){
        C();
    }
}