#include<bits/stdc++.h>
using namespace std;
int main(){
    string N; cin >> N;
    sort(N.begin(),N.end());
    int ans = 0;
    do{
        for(int i=1; i<N.size(); i++){
            string l = "", r = "";
            for(int j=0; j<i; j++) l += N[j];
            for(int j=i; j<N.size(); j++) r += N[j];
            if(l[0]=='0' || r[0]=='0') continue;
            ans = max(ans,stoi(l)*stoi(r));
        }
    }while(next_permutation(N.begin(),N.end()));
    cout << ans << endl;
}