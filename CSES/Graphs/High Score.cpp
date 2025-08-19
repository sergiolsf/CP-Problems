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

const int MAX_N = 2'505;
const int INF = 1'000'000'000'000'000'000;

int n, m;
vector<vector<pii>> adj(MAX_N);
vector<vector<pii>> uni(MAX_N);

signed main() {
    fastio();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, d; cin >> u >> v >> d;
        adj[u].push_back({v, -d});

        if (n == 1 && d > 0) {
            cout << -1 << endl;
            return 0;
        }

        int um;
        if (d > 0) um = -1;
        else um = 0;

        uni[u].push_back({v, um});
    }

    vi dist(n+1, INF); dist[1] = 0;
    for (int i = 1; i < n; i++) {
        bool modified = false;
        for (int u = 1; u <= n; u++) {
            if (dist[u] < INF) 
                for (auto &[v, w]: adj[u]) {
                    if (dist[u]+w >= dist[v]) continue;
                    dist[v] = dist[u] + w;
                    modified = true;
                }
        }
        if (!modified) break;
    }

    vi dist2(n+1, INF); dist2[1] = 0;
    for (int i = 1; i < n; i++) {
        for (int u = 1; u <= n; u++) {
            if (dist2[u] < INF) 
                for (auto &[v, w]: uni[u]) {
                    if (dist2[u]+w >= dist2[v]) continue;
                    dist2[v] = dist2[u] + w;
                }
        }
    }

    vi dist3(n+1, INF); dist3 = dist2;
    for (int i = 1; i < n; i++) {
        for (int u = 1; u <= n; u++) {
            if (dist3[u] < INF) 
                for (auto &[v, w]: uni[u]) {
                    if (dist3[u]+w >= dist3[v]) continue;
                    dist3[v] = dist3[u] + w;
                }
        }
    }
    
    
    bool hasNegativeCycle = false;
    if (dist2[n] != dist3[n]) hasNegativeCycle = true;

    if (hasNegativeCycle) cout << -1 << endl;
    else cout << -dist[n] << endl;
  
    return 0;
}