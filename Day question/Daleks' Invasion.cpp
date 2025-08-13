#include <bits/stdc++.h>
using namespace std;

//#define int long long
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
int n, m;

int INF = 1'000'000'001;
vector<vector<pii>> adj(MAX_N);
int u1, v1;
int AA = 1'000'000;

bool possible(int x) {
    vector<bool> visited(n+1, false);
    priority_queue<pii> pq; // dist, vert
    pq.push({0, u1});

    while (!pq.empty()) {

        if (visited[u1] && visited[v1]) return false;

        auto [d, u] = pq.top(); pq.pop();

        if (u == AA) return true;
        if (visited[u]) continue;
    
        visited[u] = true;

        for (auto [viz, w] : adj[u]) {
            if (visited[viz]) continue;
            if ((u1 == u && v1 == viz) || (u1 == viz && v1 == u)) {
                w = x;
                viz = AA;
            }
            pq.push({-w, viz});
        }
    }

    return false;
}

signed main() {
    fastio();
    cin >> n >> m;

    int cu = 0, cv = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, e; cin >> u >> v >> e;
        if (i == 1) {
            u1 = u; v1 = v;
        }
        adj[u].push_back({v, e});
        adj[v].push_back({u, e});
        if (u == u1 || v == u1) cu++;
        if (u == v1 || v == v1) cv++;
    }

    if (cv < cu) swap(u1, v1);

    int lo = 0, hi = INF;
    while (hi-lo > 1) {
        int m = (hi+lo)/2;
        if (possible(m)) lo = m;
        else hi = m;
    }

    cout << lo << endl;

    return 0;
}