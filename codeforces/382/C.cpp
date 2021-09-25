#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &a : v)
        cin >> a;
    sort(v.begin(), v.end());
    map<int, int> lol;
    for (int i = 1; i < v.size(); i++) {
        lol[v[i] - v[i - 1]]++;
    }
    if (v.size() == 1) {
        cout << -1;
        return 0;
    }
    if (lol.size() > 2) {
        cout << 0;
        return 0;
    }
    if (v.size() == 1) {
        cout << -1;
        return 0;
    }
    if (lol.size() == 1) {
        int x = lol.begin()->first;
        set<int> answer;
        answer = {v[0] - x, v.back() + x};
        if ((v[0] + v.back()) % 2 == 0 and n == 2)answer.insert((v[0] + v.back()) / 2);
        cout << answer.size() << endl;
        for (auto a  :answer)
            cout << a << ' ';
        return 0;
    }
    auto y = lol.rbegin();
    auto x = lol.begin();
    if (y->second == 1 && (x->first * 2) == y->first) {
        cout << 1 << endl;
        for (int i = 1; i < n; i++) {
            if (v[i] - v[i - 1] != x->first) {
                cout << v[i - 1] + x->first;
                return 0;
            }
        }
    } else {
        cout << 0;
        return 0;
    }
}
