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

vvi g;
vi visited;
int cont = 0;

void dfs(int u) {
    visited[u] = true;
    int d = 0;
    for (auto e: g[u]) {
        if (!visited[e]) {
            dfs(e);
        }
        d++;
    }
    if (d == 2) cont++;
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    g.resize(n+1);
    visited.resize(n+1, false);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);

    cout << (cont == n ? "Yes\n" : "No\n");

  
    return 0;
}