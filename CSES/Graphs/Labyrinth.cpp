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

vector<vector<char>> grid;
vector<vector<pii>> pai;
int iA, jA;
int iB, jB;
vector<pii> path = {{1,0}, {-1,0}, {0,1}, {0,-1}};

signed main() {
    fastio();
    int n, m;
    cin >> n >> m;

    grid.resize(n+1, vector<char>(m+1));
    pai.resize(n+1, vector<pii> (m+1, {0,0}));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                iA = i;
                jA = j;
            } else if (grid[i][j] == 'B') {
                iB = i;
                jB = j;
            }
        }
    }

    vector<vector<bool>> visited(n+1, vector<bool> (m+1,false));
    queue<pii> q;

    visited[iA][jA] = true;
    q.push({iA,jA});
    pai[iA][jA] = {-1,-1};

    bool flag = false;

    while (!q.empty() && !flag) {
        pii current = q.front();
        int a = current.first, b = current.second;
        q.pop();

        for (auto e : path) {
            int u = a + e.first;
            int v = b + e.second;
            if (u < 1 || v < 1 || u > n || v > m || grid[u][v] == '#') continue;
            if (!visited[u][v]) {
                visited[u][v] = true;
                q.push({u,v});
                pai[u][v] = {a, b};
                if (u == iB && v == jB) {
                    flag = true;
                    break;
                }
            }
        }
    }

    if (!flag) {
        cout << "NO" << endl;
        return 0;
    } 

    cout << "YES" << endl;
    int u = iB, v = jB;

    vector<char> ans;

    while (u != -1 && v != -1) {
        int f = pai[u][v].first;
        int s = pai[u][v].second;

        int c = u-f;
        int d = v-s;

        if (c == 1) ans.push_back('D');
        if (c == -1) ans.push_back('U');
        if (d == 1) ans.push_back('R');
        if (d == -1) ans.push_back('L');

        u = f;
        v = s;
    }

    cout << ans.size() << endl;

    for (int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i];
    }

    cout << endl;
    
    return 0;
}