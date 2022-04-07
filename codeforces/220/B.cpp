#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 55;
int sq, a[N], cnt = 0;
unordered_map<int, int> frq;
int n;

void remove(int idx);  // TODO: remove value at idx from data structure
void add(int idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

int block_size;

void remove(int idx) {
    if (frq[a[idx]] == a[idx]) {
        cnt--;
    }
    frq[a[idx]]--;
    if (frq[a[idx]] == a[idx])
        cnt++;
}

void add(int idx) {
    if (frq[a[idx]] == a[idx]) {
        cnt--;
    }
    frq[a[idx]]++;
    if (frq[a[idx]] == a[idx])
        cnt++;
}

int get_answer() {
    return cnt;
}

struct Query {
    int l, r, idx;

    bool operator<(Query other) const {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

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

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)cin >> a[i];
    block_size = sqrt(2 * n);
    vector<Query> v(q);
    int start = 0;
    for (auto &i: v) {
        cin >> i.l >> i.r;
        i.l--;
        i.r--;
        i.idx = start++;
    }
    for (auto &i: mo_s_algorithm(v)) {
        cout << i << endl;
    }
}