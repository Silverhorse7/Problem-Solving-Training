
#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> barriers;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    function<void(int, vector<int>)> generate = [&](int i, vector<int> carr = vector<int>()) {
        if (i == n) {
            barriers.push_back(carr);
            return;
        }
        carr.push_back(i);
        generate(i + 1, carr);
        carr.pop_back();
        generate(i + 1, carr);
    };
    generate(0, {});
    for (auto i: barriers)
        sort(i.begin(), i.end());
    cout << endl;
    long long mn = 9e9;
    for (auto v: barriers) {
        long long o = 0;
        long long x = 0;
        for (int j = 0; j <= n; j++) {
            if (j < n)
                o |= a[j];
            if (j == n or (binary_search(v.begin(), v.end(), j)))
                x ^= o, o = 0;
        }
        mn = min(mn, x);
    }
    cout << (mn == 9000000000 ? 0 : mn) << endl;
}
