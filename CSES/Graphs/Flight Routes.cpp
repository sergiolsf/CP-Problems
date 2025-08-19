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
int n, m, k;
vvi dist(MAX_N);
vector<vector<pii>> adj(MAX_N);

void dijkstra_modificado(int u) {
    priority_queue<pii> pq;
    pq.push({0, u});
    vector<bool> visited(n+1, false);

    while (!pq.empty()) {
        if (visited[n]) return;
        auto [d, v] = pq.top(); pq.pop();
        d = -d;
        if (visited[v]) continue;

        dist[v].push_back(d);
        if ((int) dist[v].size() == k) visited[v] = true;

        for (auto [e, w]: adj[v]) {
            if (visited[e]) continue;
            pq.push({-(w+d), e});
        }
    }
}


signed main() {
    fastio();
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, d; cin >> u >> v >> d;
        adj[u].push_back({v, d});
    }

    dijkstra_modificado(1);

    for (int i = 0; i < k; i++) {
        cout << dist[n][i] << (i == k-1 ? "\n" : " ");
    }
  
    return 0;
}