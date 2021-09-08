#include<bits/stdc++.h>
using namespace std;
#define no {cout<<"NO"<<endl;return;};
const int N = 100;
char grid[N][N];
void solve(){
    memset(grid,'.',sizeof grid);
    long long n;
    cin >> n ;
    string s;
    cin >> s ;
    vector<long long int >indices;
    long long counter = 0;
    for(int i=0;i<n;i++) {
        if (s[i] != '2')
            continue;
        counter++;
        indices.push_back(i);
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '1') continue;
        for (int j2 = 0; j2 < n; j2++) {
            grid[i][j2] = '=';
            grid[j2][i] = '=';
        }
    }
        for (int i = 0; i < indices.size(); i++) {
            for (int j = 0; j < indices.size(); j++) {
                if (i != j) {
                    if (grid[indices[i]][indices[j]] == '.') {
                        grid[indices[i]][indices[j]] = '=';
                        grid[indices[i]][indices[j]] = '=';
                    }
                }
            }
            if (i != indices.size() - 1) {
                grid[indices[i]][indices[i + 1]] = '+';
                grid[indices[i + 1]][indices[i]] = '-';
            } else {
                grid[indices[i]][indices[0]] = '+';
                grid[indices[0]][indices[i]] = '-';
            }
        }
    if (counter <= 2 && counter)no;

    cout << "YES"<<endl;
    for (int i = 0; i < n; i++) {
            grid[i][i] = 'X';
            for (int j = 0; j < n; j++)cout << grid[i][j];cout<<endl;
        }
}
signed main() {
int t;
cin>>t;
while(t--)solve();
}