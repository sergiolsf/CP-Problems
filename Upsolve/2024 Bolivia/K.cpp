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

const int MAX_N = 1'005;

int n, m;

vector<vector<char>> grid (MAX_N, vector<char> (MAX_N));
vector<vector<bool>> visited (MAX_N, vector<bool> (MAX_N, false));

vector<pii> vp = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool pode (int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    if (grid[x][y] == '#') return false;
    return true;
}

int dfs(int x, int y) {
    visited[x][y] = true;
    int ans = 0;
    if (grid[x][y] != '.' && grid[x][y] != 'S') {
        ans += (int) (grid[x][y]-'0');
    }
    for (auto p: vp) {
        if (pode(x+p.first,y+p.second) && grid[x+p.first][y+p.second] == 'T') return ans;
    }
    for (auto p: vp) {
        if (!visited[x+p.first][y+p.second] && pode(x+p.first, y+p.second)) {
            ans += dfs(x+p.first, y+p.second);
        }
    }
    return ans;
} 

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = false;
        }
    }
}

signed main() {
    fastio();
    while (cin >> n >> m) {
        int inii, inij;
        init();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'S') {
                    inii = i; inij = j;
                }
            }
        }
        cout << dfs(inii, inij) << endl;
    }
  
    return 0;
}