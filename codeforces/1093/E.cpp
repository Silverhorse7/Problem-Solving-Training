#include "bits/stdc++.h"

using namespace std;
#define sz(x) (int)(x).size()
const int Block_size = 550, N = 2e5 + 55;
vector<int> Block[Block_size];
int a[N], b[N], PosA[N], PosB[N];

void remove(int &ind, int &x) {
    int B = ind / Block_size;
    for (int i = 0; i < sz(Block[B]); i++) {
        if (Block[B][i] == x) {
            for (int j = i + 1; j < sz(Block[B]); j++) {
                swap(Block[B][j], Block[B][j - 1]);
            }
            break;
        }
    }
    Block[B].resize(sz(Block[B]) - 1);
}

void add(int &ind, int &x) {
    int B = ind / Block_size;
    Block[B].push_back(x);
    for (int j = sz(Block[B]) - 1; j > 0; j--) {
        if (Block[B][j] < Block[B][j - 1]) {
            swap(Block[B][j], Block[B][j - 1]);
        }
    }
}

void update(int x, int y) {
    remove(PosA[b[x]], x);
    remove(PosA[b[y]], y);
    swap(b[x], b[y]);
    swap(PosB[b[x]], PosB[b[y]]);
    add(PosA[b[x]], x);
    add(PosA[b[y]], y);
}

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, Q;
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        PosA[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        Block[PosA[b[i]] / Block_size].push_back(i);
        PosB[b[i]] = i;
    }
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int la, ra, lb, rb;
            cin >> la >> ra >> lb >> rb;
            int ans = 0;
            for (; la <= ra and (la) % Block_size != 0; la++) {
                int pos = PosB[a[la]];
                if (lb <= pos && pos <= rb) ans++;
            }
            for (; la + Block_size - 1 <= ra; la += Block_size) {
                int cur_block = la / Block_size;
                int semi_ans = lower_bound(Block[cur_block].begin(), Block[cur_block].end(), rb + 1)
                               - lower_bound(Block[cur_block].begin(), Block[cur_block].end(), lb);
                ans += semi_ans;
            }
            for (; la <= ra; la++) {
                int pos = PosB[a[la]];
                if (lb <= pos && pos <= rb) ans++;
            }
            cout << ans << endl;
        } else {
            int x, y;
            cin >> x >> y;
            update(x, y);
        }
    }
}