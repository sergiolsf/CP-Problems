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
const int INF = 1'000'000'000'000'000'000;

int h, w; 
vector<vector<char>> grid(MAX_N, vector<char> (MAX_N));
vector<vector<bool>> visited(MAX_N, vector<bool> (MAX_N, false));
vvi dist(MAX_N, vi (MAX_N, INF));
vector<pii> cam = {{1,0}, {-1,0}, {0,-1}, {0,1}};
vector<char> pos = {'^', 'v', '>', '<'};

bool possible (int x, int y, int d) {
    if (x < 1 || y < 1 || x > h || y > w) return false;
    if (grid[x][y] == 'E' || grid[x][y] == '#') return false;
    if (dist[x][y] <= d) return false;
    return true;
}

int dfs(int x, int y) {
    int d = INF;
    if (visited[x][y])
    visited[x][y] = true;
    
    if (grid[x][y] == 'E') return dist[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        if (possible(x+cam[i].first, y+cam[i].second)) {
            int d1 = dfs(x+cam[i].first, y+cam[i].second);
            if (d > d1) {
                d = d1;
                grid[x+cam[i].first][y+cam[i].second] = pos[i];
            }
        }
    }

    /*
    for (int i = 0; i < 4; i++) {
        if (possible(x+cam[i].first, y+cam[i].second, dist[x][y]+1)) {
            dist[x+cam[i].first][y+cam[i].second] = dist[x][y]+1;
            grid[x+cam[i].first][y+cam[i].second] = pos[i];
            dfs(x+cam[i].first, y+cam[i].second);
        }
    }*/
}

signed main() {
    fastio();
    cin >> h >> w;
    vector<pii> escape;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'E') {
                escape.push_back({i, j});
            }
        }
    }

    for (auto e: escape) {
        dist[e.first][e.second] = 0;
        dfs(e.first, e.second);
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}