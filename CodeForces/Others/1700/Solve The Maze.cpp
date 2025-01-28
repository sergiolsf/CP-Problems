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

int n, m;
vector<vector<char>> maze(51, vector<char> (51));
vector<pii> bad, good;
vector<pii> path = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool walls(int x, int y) {
    for (auto e: path) {
        int a = x+e.first, b = y+e.second;
        if (a > 0 && a <= n && b > 0 && b <= m) {
            if (maze[a][b] == '.') {
                maze[a][b] = '#';
            } else if (maze[a][b] == 'G') {
                return true;
            }
        }
    }
    return false;
}

vector<vector<bool>> visited (51, vector<bool> (51));
int cont;

void dfs (int x, int y) {
    if (maze[x][y] == '#') return;
    if (maze[x][y] == 'G') cont++;

    visited[x][y] = true;

    for (auto e: path) {
        int a = x+e.first, b = y+e.second;
        if (a >= 1 && b >= 1 && a <= n && b <= m) {
            if (!visited[a][b]) {
                dfs(a,b);
            }   
        }
    }
}

void solve() {
    cin >> n >> m;

    bad.clear();
    good.clear();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'B') {
                bad.push_back({i, j});
            } else if (maze[i][j] == 'G') {
                good.push_back({i,j});
            }
        }
    }

    if (good.size() == 0) {
        cout << "Yes\n";
        return;
    }

    for (auto e: bad) {
        int x = e.first, y = e.second;
        if (walls(x, y)) {
            cout << "No\n";
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = false;
        }
    }

    cont = 0;
    dfs(n, m);

    if (cont != good.size()) {
        cout << "No\n";
        return;
    }
    
    cout << "Yes\n";
    return;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}