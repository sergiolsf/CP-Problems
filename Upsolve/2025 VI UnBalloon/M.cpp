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
const int INF = 1'000'000'000'000'000'000;

int n, m, menorDist; 
vi dist(MAX_N, INF);

vector<vector<pii>> g(MAX_N);

bool dijkstra(int D) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        auto [d, u] = pq.top(); 
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w]: g[u]) {
            if (w > D) continue;
            if (dist[u]+w >= dist[v]) continue;
            dist[v] = dist[u]+w;
            pq.push({dist[v], v});
        }
    }

    return (dist[n] == menorDist);
}

void init() {
    for (int i = 0; i <= n; i++) dist[i] = INF;
}

signed main() {
    fastio();
    init();

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
    }

    bool c = dijkstra(INF);
    menorDist = dist[n];

    int lo = 0, hi = 100'000;
    while (hi-lo > 1) {
        int m = (hi+lo)/2;
        init();
        if (dijkstra(m)) hi = m;
        else lo = m;
    }

    cout << menorDist << " " << hi << endl; 

    return 0;
}