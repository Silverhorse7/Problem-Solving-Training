#include<bits/stdc++.h>

using namespace std;

int main() {
    queue<int> q;
    priority_queue<int, vector<int>, greater<>> pq;
    int Q;
    cin >> Q;

    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            q.push(x);
        }
        if (op == 2) {
            if (pq.empty()) {
                cout << q.front() << endl;
                q.pop();
            } else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        if (op == 3) {
            while (!q.empty()) {
                pq.push(q.front());
                q.pop();
            }
        }
    }
}