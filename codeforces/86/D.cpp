
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2e6, block_size = 500;
long long ans;
int frq[N], a[N];

struct Query {
    int l, r, idx;

    bool operator<(Query other) const {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

long long calc(int idx) {
    return frq[a[idx]] * frq[a[idx]] * a[idx];
}

void remove(int idx) {
    long long old = calc(idx);
    frq[a[idx]]--;
    long long New = calc(idx);
    ans -= old;
    ans += New;
}

void add(int idx) {
    long long old = calc(idx);
    frq[a[idx]]++;
    long long New = calc(idx);
    ans -= old;
    ans += New;
}

int get_answer() {
    return ans;
}

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q: queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

signed main() {
    int n, Q;
    cin >> n >> Q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<Query> q(Q);
    int id = 0;
    for (auto &i: q)
        cin >> i.l >> i.r, i.idx = id++;
    for (auto i: mo_s_algorithm(q))
        cout << i << endl;
}