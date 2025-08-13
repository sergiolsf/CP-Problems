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

vector<vector<pii>> adj(MAX_N);
vector<bool> marcado(MAX_N);
vector<bool> visited(MAX_N);
int ans = 0;

void prim(int u) {
    priority_queue<pii> pq;
    pq.push({0, u});

    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (marcado[u]) continue;
        ans += -dist;
        marcado[u] = true;
        for (auto [b, w]: adj[u]) {
            if (marcado[b]) continue;
            pq.push({-w, b});
        }
    }
}

void dfs(int u) {
    visited[u] = true;
    for (auto [b, w]: adj[u]) {
        if (visited[b]) continue;
        dfs(b);
    }
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    prim(1);
    cout << ans << endl;
  
    return 0;
}