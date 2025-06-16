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

int n, m, x; 
vector<vector<pii>> adj(MAX_N);
vector<bool> visited(MAX_N);

bool dfs(int u, int k) {
    visited[u] = true;

    if (u == n) return true;

    bool f = false;
    for (auto [e, w]: adj[u]) {
        if (visited[e] || (k|w) > k) continue;
        f |= dfs(e, k);
    }
    return f;
}

void init() {
    for (int i = 0; i < MAX_N; i++) {
        visited[i] = false;
    }
}

signed main() {
    fastio();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    x = (1LL<<30)-1;
    for (int i = 29; i >= 0; i--) {
        init();
        if(dfs(1, x-(1LL<<i))) x -= 1LL<<i;
    }

    cout << x << endl;  
    return 0;
}