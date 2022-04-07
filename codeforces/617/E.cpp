#include<bits/stdc++.h>

using namespace std;
const long long N = 1e5 + 55;
long long sq, a[N], cnt = 0, b[N];
unordered_map<long long, long long> frq;
long long n, q, k;

void remove(long long idx);  // TODO: remove value at idx from data structure
void add(long long idx);     // TODO: add value at idx from data structure
long long get_answer();  // TODO: extract the current answer of the data structure

long long block_size;

void remove(long long idx) {
    long long x = b[idx] ^ k;
    frq[b[idx]]--;
    cnt -= frq[x];
}

void add(long long idx) {
    long long x = b[idx] ^ k;
    cnt += frq[x];
    frq[b[idx]]++;
}

long long get_answer() {
    return cnt;
}

struct Query {
    long long l, r, idx;

    bool operator<(Query other) const {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

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
        answers[q.idx] = get_answer();
    }
    return answers;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> q >> k;
    for (long long i = 0; i < n; i++)cin >> a[i];
    for (long long i = 1; i <= n; i++)
        b[i] = b[i - 1] ^ a[i - 1];
    block_size = sqrt(2 * n);
    vector<Query> v(q);
    long long start = 0;
    for (auto &i: v) {
        cin >> i.l >> i.r;
        i.l--;
        i.idx = start++;
    }
    for (auto &i: mo_s_algorithm(v)) {
        cout << i << endl;
    }
}