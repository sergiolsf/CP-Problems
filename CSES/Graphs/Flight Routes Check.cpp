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

const int MAX_N = 100'005;

vvi adj(MAX_N);
vvi inv(MAX_N);
vector<bool> visited(MAX_N);
vector<bool> vis(MAX_N);
vector<bool> marc(MAX_N);
stack<int> ordem;
vi val(MAX_N);

int n, m;

void dfs(int u) {
    visited[u] = true;
    for (auto e: adj[u]) {
        if (visited[e]) continue;
        dfs(e);
    }
    ordem.push(u);
}

void busca(int u, int k) {
    marc[u] = true;
    val[u] = k;
    for (auto e: inv[u]) {
        if (marc[e]) continue;
        busca(e, k);
    }
}

bool consigo (int u, int v) {
    if (u == v) return true;
    vis[u] = true;
    bool flag = false;
    for (auto e: adj[u]) {
        if (vis[e]) continue;
        flag |= consigo (e, v);
    }
    return flag;
}

signed main() {
    fastio();
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        inv[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    int k = 0;
    while (!ordem.empty()) {
        int u = ordem.top(); ordem.pop();
        if (marc[u]) continue;
        ++k;
        busca(u, k);
    }

    if (k == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        int v1, v2;
        for (int i = 1; i <= n; i++) {
            if (val[i] == 1) v1 = i;
            else v2 = i;
        }

        if (consigo (v1, v2)) {
            cout << v2 << " " << v1 << endl;
        } else cout << v1 << " " << v2 << endl;
    }
  
    return 0;
}