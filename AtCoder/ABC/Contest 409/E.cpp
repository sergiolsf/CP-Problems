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

int n; 
vi x(MAX_N);
vector<vector<pii>> adj(MAX_N);
vector<bool> visited(MAX_N, false);
int ans = 0;

void dfs(int u) {
    visited[u] = true;
    int cont = 0;
    for (auto [v, w]: adj[u]) {
        if (!visited[v]) {
            dfs(v);
            cont += x[v];
            ans += abs(x[v])*w;
        }
    }
    x[u] += cont;
}

signed main() {
    fastio();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1);
    cout << ans << endl;
  
    return 0;
}