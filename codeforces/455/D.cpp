#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
const int sqr = 318;
int a[N], n, mp[N / sqr + 55][N];
deque<int> dq[N / sqr + 3];

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dq[i / sqr].push_back(a[i]);
        mp[i / sqr][a[i]]++;
    }
}

int solve(int l, int r, int k) {
    long long ans = 0;
    for (int i = l; i <= r;) {
        if (i % sqr == 0 and i + sqr - 1 <= r) {
            ans += mp[i / sqr][k];
            i += sqr;
        } else {
            ans += (dq[i / sqr][i % sqr] == k);
            i++;
        }
    }
    return ans;
}

void update(int l, int r) {
    int val = dq[r / sqr][r % sqr];
    dq[r / sqr].erase(dq[r / sqr].begin() + (r % sqr));
    mp[r / sqr][val]--;
    dq[l / sqr].insert(dq[l / sqr].begin() + (l % sqr), val);
    mp[l / sqr][val]++;
    for (int i = l / sqr; i < r / sqr; i++) {
        int val = dq[i].back();
        dq[i + 1].push_front(val);
        mp[i + 1][val]++;
        mp[i][val]--;
        dq[i].pop_back();
    }
}

void queries() {
    int q;
    cin >> q;
    int last_ans = 0;
    while (q--) {
        int ch, l, r;
        cin >> ch >> l >> r;
        l = (l + last_ans - 1) % n + 1;
        r = (r + last_ans - 1) % n + 1;
        if (l > r)swap(l, r);
        l--, r--;
        if (ch == 1) {
            update(l, r);
        } else {
            int k;
            cin >> k;
            k = (k + last_ans - 1) % n + 1;
            last_ans = solve(l, r, k);
            cout << last_ans << endl;
        }
    }
}

int main() {
    init();
    queries();
}