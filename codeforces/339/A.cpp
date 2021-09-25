#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i += 2) {
        for (int j = i + 2; j < s.size(); j += 2) {
            if (s[j] < s[i])swap(s[i], s[j]);
        }
    }
    cout << s;
}
