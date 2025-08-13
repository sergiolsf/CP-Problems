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

int n, m, x, y;
vvi adj(MAX_N);
bool visited[MAX_N];
stack<int> ans;

bool dfs(int u) {
    visited[u] = true;
    
    if (u == y) {
        ans.push(u);
        return true;
    }

    bool d = false;
    for (auto e: adj[u]) {
        if (visited[e]) continue;
        d |= dfs(e);
        if (d) break;
    }

    if (d) ans.push(u);
    return d;
}


void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        visited[i] = false;
    }
}

void solve() {
    cin >> n >> m >> x >> y;
    init();

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(all(adj[i]));
    }

    bool d = dfs(x);

    bool first = true;
    while (!ans.empty()) {
        if (!first) cout << " ";
        cout << ans.top();
        first = false;
        ans.pop();
    }
    cout << endl;
}

signed main() {
    fastio();
    int t; cin >> t; 
    while (t--) {
        solve();
    }  
    return 0;
}