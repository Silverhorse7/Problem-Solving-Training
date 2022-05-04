#include "bits/stdc++.h"

using namespace std;
int Cnt = 0;

class test {
    int n;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> parent;
    int cycle_start, cycle_end;

    bool dfs(int v, int par) { // passing vertex and its parent vertex
        visited[v] = true;
        for (int u: adj[v]) {
            if (u == par) continue; // skipping edge to parent vertex
            if (visited[u]) {
                cycle_end = v;
                cycle_start = u;
                return true;
            }
            parent[u] = v;
            if (dfs(u, parent[u]))
                return true;
        }
        return false;
    }

    void find_cycle(vector<int> A) {
        visited.assign(n, false);
        parent.assign(n, -1);
        cycle_start = -1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && dfs(v, parent[v]))
                break;
        }

        if (cycle_start == -1) {
            cout << "Not Cycle :";
            for (auto i: A)cout << i << ' ';
            cout << endl;
        } else {
            return;
            vector<int> cycle;
            cycle.push_back(cycle_start);
            for (int v = cycle_end; v != cycle_start; v = parent[v])
                cycle.push_back(v);
            cycle.push_back(cycle_start);
            reverse(cycle.begin(), cycle.end());
            Cnt++;
            cout << "Cycle found: ";
            for (auto i: A)cout << i << ' ';
            cout << endl;
        }
    }

public :
    test(vector<int> v) {
        adj.resize(v.size() + 1212);
        n = v.size();
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (v[j] > v[i]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    break;
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (v[j] > v[i]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    break;
                }
            }
        }
        find_cycle(v);
    }
};

const int N = 1e7 + 5, mod = 1e9 + 7;
long long factorialNumInverse[N + 1];
long long naturalNumInverse[N + 1];
long long fact[N + 1];

void InverseofNumber(long long p) {
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}

void InverseofFactorial(long long p) {
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

void factorial(long long p) {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

long long Binomial(long long N, long long R, long long p) {

    long long ans = ((fact[N])
                     % p * factorialNumInverse[N - R])
                    % p;
    return ans;
}

long long fastpow(long long base, long long power, long long M) {
    if (power == 0) return 1;
    if (power == 1) return base;
    long long val = fastpow(base, power / 2, M);
    return (power % 2 == 0) ? (val * val) % M : (((val * val) % M) * base) % M;
}

signed main() {
    InverseofNumber(mod);
    InverseofFactorial(mod);
    factorial(mod);
    long long n;
    cin >> n;
    cout << (fact[n] - fastpow(2, n - 1, mod)+mod)%mod << endl;
}