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

const int MAXN = 300'010;
const int MAXH = 1'000'000'010;
const int INF = 1e18;

int n, m, k;
vector<vector<pii>> g(MAXN);

bool bfs(int h) {
    vi dist(n + 1, INF);
    deque<int> dq;

    dist[1] = 0;
    dq.push_front(1);

    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (auto e : g[u]) {
            int v = e.first, po = e.second;
            int peso = (po <= h ? 0 : 1);
            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                if (peso == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }

    return (dist[n] <= k);
}

signed main() {
    fastio();
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, h; cin >> u >> v >> h;
        g[u].push_back({v, h});
        g[v].push_back({u, h});
    }

    int lo = 0, hi = MAXH;
    while (hi-lo > 1) {
        int m = (hi + lo) / 2;
        if (bfs(m)) hi = m;
        else lo = m+1;
    }

    for (int i = lo; i <= hi; i++) {
        if (bfs(i)) {
            cout << i << endl;
            break;
        }
    }
  
    return 0;
}