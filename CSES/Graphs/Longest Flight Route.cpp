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
const int INF = 1'000'000'000'000;

int n, m;
vvi adj(MAX_N);
vector<bool> visited(MAX_N);
stack<int> ordem;
vi dist(MAX_N, -INF);
vi pai(MAX_N);

void dfs(int u) {
    visited[u] = true;
    for (auto e: adj[u]) {
        if (visited[e]) continue;
        dfs(e);
    }
    ordem.push(u);
}

signed main() {
    fastio();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    dfs(1);

    vi ord;
    int k = 0, ini;

    if (!visited[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    while (!ordem.empty()) {
        int u = ordem.top(); ordem.pop();
        if (u == n) ini = k;
        ord.push_back(u);
        ++k;
    }

    dist[n] = 0;

    for (int i = ini-1; i >= 0; i--) {
        int u = ord[i];
        int maior = -INF, noh = 0;
        for (auto e: adj[u]) {
            if (dist[e] >= maior) {
                maior = dist[e]+1;
                noh = e;
            }
        }
        pai[u] = noh;
        dist[u] = maior;
    }

    int u = 1;
    vi ans;
    ans.push_back(1);
    while (u != n) {
        u = pai[u];
        ans.push_back(u);
    }
    cout << ans.size() << endl;
    for (auto e: ans) cout << e << " ";
    cout << endl;

    return 0;
}