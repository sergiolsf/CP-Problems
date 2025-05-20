#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int MAX_N = 1005;

vvi grid(MAX_N, vi (MAX_N, -1));
int n;
vector<pii> passos = {{2, -1}, {2, 1}, {-1, 2}, {1, 2}, {-2, -1}, {-2, 1}, {-1, -2}, {1, -2}};

bool impossivel (int x, int y) {
    if (x < 1 || y < 1 || x > n || y > n) return true;
    if (grid[x][y] != -1) return true;
    return false;
}

void bfs (int x, int y) {
    queue<pii> q;
    q.push({x, y});
    grid[x][y] = 0;

    while (!q.empty()) {
        pii s = q.front(); q.pop();
        for (auto e: passos) {
            int u = s.first+e.first;
            int v = s.second+e.second;
            if (impossivel(u, v)) continue;
            int &g = grid[u][v];
            g = grid[s.first][s.second]+1;
            q.push({u, v});
        }
    }
}

signed main() {
    fastio();
    cin >> n;
    grid[1][1] = 0;
    bfs(1, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j] << (j == n ? "\n" : " ");
        }
    }
  
    return 0;
}