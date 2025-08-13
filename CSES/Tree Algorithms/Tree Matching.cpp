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
int ans = 0;

bool dfs(int u) {
    visited[u] = true;
    bool d = true;
    for (auto e: adj[u]) {
        if (visited[e]) continue;
        d &= dfs(e);
    }
    if (!d) ans++;
    return !d;
}

signed main() {
    fastio();
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool d = dfs(1);

    cout << ans << endl;
  
    return 0;
}