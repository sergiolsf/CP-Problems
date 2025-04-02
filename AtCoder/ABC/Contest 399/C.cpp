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

const int MAX_N = 200'010;

int n, m, ans = 0;
vvi g(MAX_N);
vector<bool> visited(MAX_N, false);
vi pai(MAX_N, -1);

void dfs(int u) {
    visited[u] = true;
    for (auto e: g[u]) {
        if (!visited[e]) {
            pai[e] = u;
            dfs(e);
        }
        else if (e != pai[u]) ans++;
    }
}

signed main() {
    fastio();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    cout << ans/2 << endl;  
    return 0;
}