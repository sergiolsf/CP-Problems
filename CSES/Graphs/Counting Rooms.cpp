#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool visited[1005][1005];
vector<vector<char>> grid;
int n, m;
vector<pii> path = {{0,1}, {1,0}, {-1,0}, {0,-1}};

void dfs (int i, int j) {
    if (i < 1 || j < 1 || i > n || j > m) return;
    if (grid[i][j] == '#') return;
    visited[i][j] = true;
    for (auto e: path) {
        int u = e.first, f = e.second;
        if (!visited[i+u][j+f]) dfs (i+u, j+f);
    }
}

signed main() {
    fastio();
    
    cin >> n >> m;
    grid.resize(n+1, vector<char>(m+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i,j);
                ans++;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}