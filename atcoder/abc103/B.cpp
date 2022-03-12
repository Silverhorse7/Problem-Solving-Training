#include "bits/stdc++.h"

using namespace std;

int main() {
    string s, t, x;
    cin >> s >> t;
    x = s;
    if(s == t){
        cout << "Yes" << endl;
        return 0;
    }
    while(true){
        string now = "";
        now += x.back();
        for(int i = 0; i < s.size()-1; i++){
            now += x[i];
        }
        if(now == t){
            cout << "Yes" << endl;
            return 0;
        }
        if(now == s){
            cout << "No" << endl;
            return 0;
        }
        x = now;
    }

}
 