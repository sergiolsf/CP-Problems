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

vvi g;
vector<bool> visited;
int dist = 0, vert;

void dfs(int u, int c) {
    if (c > dist)  { vert = u; dist = c; }
    visited[u] = true;
    for (auto e: g[u]) {
        if (!visited[e]) {
            dfs(e, c+1);
        }
    }
}

signed main() {
    fastio();
    int n;
    cin >> n;

    g.resize(n+1);
    visited.resize(n+1, false);
    

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);
    dist = 0;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    dfs(vert, 0);

    cout << dist << endl;

    
    return 0;
}