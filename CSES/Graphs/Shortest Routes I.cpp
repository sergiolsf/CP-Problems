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
const int INF = 1e18;
vector<vector<pii>> g(MAX_N);
vi dist(MAX_N, INF);
vector<bool> processed(MAX_N, false);

void dijkstra(int u) {
    priority_queue<pii> q;
    dist[u] = 0;
    q.push({0, u});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto [b, w] : g[a]) {
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b], b});
            }
        }
    }
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    dijkstra(1);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
  
    return 0;
}