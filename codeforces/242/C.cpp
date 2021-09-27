#include<bits/stdc++.h>

#define ll long long
#define all(x) x.begin(),x.end()
#define yes {cout<<"YES"<<endl;return;}
#define no {cout<<"NO"<<endl;return;}
using namespace std;
int dx[] = {0, 1, 0, 1, 1, -1, -1, -1};
int dy[] = {-1, -1, 1, 0, 1, 1, -1, 0};
map<pair<int, int>, bool> allowed;
map<pair<int, int>, bool> visited;
map<pair<int, int>, int> dist;
queue<pair<int, int>> q;

void enter(pair<int, int> &b) {
    cin >> b.first >> b.second;
}

bool valid(int x, int y) {
    return (x >= 0 and y >= 0 and allowed[{x, y}] and !visited[{x, y}]);
}

int main() {
    pair<int, int> start, finish;
    enter(start);
    enter(finish);
    int n;
    cin >> n;
    while (n--) {
        int a, l, r;
        cin >> a >> l >> r;
        for (int i = l; i <= r; i++) {
            allowed[{a, i}] = 1;
        }
    }
    q.push(start);
    visited[start] = 1;
    dist[start] = 0;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node == finish) {
            return cout << dist[node], 0;
        }
        for (int i = 0; i < 8; i++) {
            int x, y;
            x = dx[i] + node.first, y = dy[i] + node.second;
            if (valid(x, y)) {
                q.push({x,y});
                dist[{x,y}]=dist[node]+1;
                visited[{x,y}]=1;
            }
        }
    }
    cout<<-1;return 0;
}