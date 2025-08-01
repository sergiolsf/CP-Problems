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

bool visited[MAX_N];
bool vis[MAX_N];
bool road[MAX_N];
vi nodes;
vvi adj(MAX_N);

int n, m, a, b;

bool dfs (int u) {
    if (u == b) return true;
    visited[u] = true;
    bool ans = false;
    for (auto e: adj[u]) {
        if (visited[e]) continue;
        ans |= dfs(e);
    }
    if (ans && u != a) nodes.push_back(u);
    return ans;
}

void search(int u) {
    if (u == a || u == b) return;
    road[u] = true;
    for (auto e: adj[u]) {
        if (road[e]) continue;
        search(e);
    }
}

int qnt(int u) {
    vis[u] = true;
    int cont = 1;
    for (auto e: adj[u]) {
        if (vis[e] || road[e]) continue;
        cont += qnt(e);
    }
    return cont;
}

void init() {
    nodes.clear();
    for (int i = 0; i <= n; i++) {
        visited[i] = vis[i] = road[i] = false;
        adj[i].clear();
    }
}

void solve() {
    cin >> n >> m >> a >> b;
    init();
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(a);

    for (auto e: nodes) {
        if (!road[e]) search(e);
    }

    vis[a] = vis[b] = true;
    int contA = qnt(a);
    int contB = qnt(b);
    //cout << contA << " " << contB << endl;
    cout << (contA-1)*(contB-1) << endl;
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