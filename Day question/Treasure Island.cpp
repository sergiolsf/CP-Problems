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

vector<vector<char>> grid;
vector<vector<bool>> visited;

int n, m;

bool possible (int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    if (grid[x][y] == '#' || visited[x][y]) return false;
    return true;
}

bool dfs(int x, int y, int direcao) {
    if (x == n && y == m) {
        return true;
    }

    visited[x][y] = true;

    int sx = direcao, sy = (direcao+1)%2;
    
    if (possible(x+sx, y+sy)) {
        if (dfs(x+sx, y+sy, direcao)) {
            return true;
        }
    } 
    if (possible(x+sy, y+sx)) {
        if (dfs(x+sy, y+sx, direcao)) {
            return true;
        }
    } 

    return false;
}

signed main() {
    fastio();

    cin >> n >> m;

    grid.resize(n+1, vector<char> (m+1));
    visited.resize(n+1, vector<bool> (m+1, false));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    bool cima = dfs(1, 1, 0);
    bool baixo = dfs(1, 1, 1);

    if (!cima) {
        cout << 0 << endl;
    } else if (!baixo) {
        cout << 1 << endl;
    } else cout << 2 << endl;

  
    return 0;
}