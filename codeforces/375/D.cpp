#include <bits/stdc++.h>

#define ll long long
#define el '\n'
using namespace std;
const int N = 1e5 + 5, INF = 1e9 + 5, mod = 1e9 + 7;
int n, m, col[N], L[N], R[N], a[N], timer;
vector<int> g[N];

void dfs(int node, int par) {
    a[timer] = col[node];
    L[node] = timer++;
    for (auto ch: g[node]) {
        if (ch == par)
            continue;
        dfs(ch, node);
    }
    R[node] = timer - 1;
}

const int root = 320, block_size = 375;
int ans[N], freq[N], freq2[N];

void add(int idx) {
    freq[a[idx]]++;
    freq2[freq[a[idx]]]++;
}

void remove(int idx) {
    freq2[freq[a[idx]]]--;
    freq[a[idx]]--;
}

int get_ans(int k) {
    return freq2[k];
}

struct Query {
    long long l, r, idx;
    long long k;

    bool operator<(Query other) const {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<Query> queries;

vector<long long> mo_s_algorithm(vector<Query> queries) {
    vector<long long> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    long long cur_l = 0;
    long long cur_r = -1;
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
        answers[q.idx] = get_ans(q.k);
    }
    return answers;
}

int cnt = 0;

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1,0);
    queries.resize(m);
    for (auto &i: queries) {
        int node;
        cin >> node >> i.k;
        i.l = L[node], i.r = R[node];
        i.idx = cnt++;
    }
    for (auto i: mo_s_algorithm(queries))
        cout << i << endl;
}