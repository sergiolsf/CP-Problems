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

const int MAX_N = 200'005;

vvi adj(MAX_N);
bool visited[MAX_N];
int n, vertice;
bool flag;

void init() {
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= n; i++) visited[i] = false;
}

void initVisit() {
    for (int i = 1; i <= n; i++) visited[i] = false;
}

void dfs(int u) {
    if (flag) return;
    visited[u] = true;

    if ((int) adj[u].size() == 2) {
            vertice = u;
            flag = true;
            return;
    } 

    for (auto e: adj[u]) {
        if (!visited[e]) dfs(e);
    }
}

void dfsPrint (int w, bool sentido) {
    visited[w] = true;
    for (auto e: adj[w]) {
        if (visited[e]) continue;
        if (sentido) cout << w << " " << e << endl;
        else cout << e << " " << w << endl;
        dfsPrint(e, !sentido);
    }
}

void solve() {
    cin >> n;
    init();
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 2) {
        cout << "NO\n";
        return;
    }

    flag = false;
    dfs(1);

    if (!flag) {
        cout << "NO\n";
        return;
    }

    int u = vertice;
    int v = adj[u][0], w = adj[u][1];

    initVisit();

    cout << "YES\n";
    cout << u << " " << v << endl;
    cout << w << " " << u << endl;

    visited[u] = true;
    dfsPrint(w, true);
    dfsPrint(v, false);
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