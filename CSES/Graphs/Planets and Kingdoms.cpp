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
vvi inv(MAX_N);
int n, m;
stack<int> ordem;
vi ans(MAX_N);

vector<bool> visited(MAX_N);
vector<bool> marc(MAX_N);

void dfs (int u) {
    visited[u] = true;
    for (auto e: adj[u]) {
        if (visited[e]) continue;
        dfs(e);
    }
    ordem.push(u);
}

void busca (int u, int k) {
    marc[u] = true;
    ans[u] = k;
    for (auto e: inv[u]) {
        if (marc[e]) continue;
        busca(e, k);
    } 
}

signed main() {
    fastio();
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inv[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i);
    }

    int k = 1;
    while (!ordem.empty()) {
        auto u = ordem.top(); ordem.pop();
        if (marc[u]) continue;
        busca(u, k);
        ++k;
    }

    cout << k-1 << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << (i == n ? "\n" : " ");
  
    return 0;
}