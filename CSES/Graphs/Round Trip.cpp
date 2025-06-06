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

int ini = -1;
int I;
vi pai(MAX_N);
vector<bool> visited(MAX_N, false);

void dfs(int u) {
    visited[u] = true;
    for (auto v: adj[u]) {
        if (visited[v]) {
            if (v != pai[u] && ini == -1) {
                ini = v;
                I = u;
            }
            continue;
        }
        pai[v] = u;
        dfs(v);
    }
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n && ini == -1; i++) {
        if (!visited[i]) dfs(i);
    }

    if (ini == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vi ans;
    ans.push_back(ini);
    int u = I;

    while (u != ini && u != 0) {
        ans.push_back(u);
        u = pai[u];
    }
    ans.push_back(u);

    cout << ans.size() << endl;
    for (auto e: ans) cout << e << " ";
    cout << endl;
  
    return 0;
}