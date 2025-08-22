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

const int INF = 1'000'000'000'000'000'000;
const int MAX_N = 100'005;
const int MOD = 1'000'000'007;

int dist[MAX_N];
int nRoutes[MAX_N];
int minFlights[MAX_N];
int maxFlights[MAX_N];

vector<vector<pii>> adj(MAX_N);
int n, m; 

void dijkstra() {
    priority_queue<pii> q;
    vector<bool> processed(n+1, false);
    dist[1] = 0;
    nRoutes[1] = 1;
    q.push({0, 1});

    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;

        for (auto [b, w] : adj[a]) {
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                nRoutes[b] = nRoutes[a];
                minFlights[b] = minFlights[a]+1;
                maxFlights[b] = maxFlights[a]+1;
                q.push({-dist[b], b}); 
            } else if (dist[a]+w == dist[b]) {
                nRoutes[b] = (nRoutes[b] + nRoutes[a])%MOD;
                minFlights[b] = min(minFlights[b], minFlights[a]+1);
                maxFlights[b] = max(maxFlights[b], maxFlights[a]+1);
            }
        }
    }
}

void init() {
    for (int i = 0; i < MAX_N; i++) {
        dist[i] = INF;
    }
}

signed main() {
    fastio();
    init();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, d; cin >> u >> v >> d;
        adj[u].push_back({v, d});
    }

    dijkstra();

    cout << dist[n] << " " << nRoutes[n] << " " << minFlights[n] << " " << maxFlights[n] << endl;  
    return 0;
}