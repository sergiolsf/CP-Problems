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
const int INF = 1'000'000'000'000'000'000;

vector<vector<pii>> adj(MAX_N);
vector<vector<pii>> adjInv(MAX_N);
vi dist(MAX_N, INF);
vi distInv(MAX_N, INF);
int n, m; 

void dijkstra() {
    priority_queue<pii> q;
    vector<bool> processed(n+1, false);
    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto [b, w] : adj[a]) {
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b], b});
            }
        }
    }
}

void dijkstraInv() {
    priority_queue<pii> q;
    vector<bool> processed(n+1, false);
    distInv[n] = 0;
    q.push({0, n});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto [b, w] : adjInv[a]) {
            if (distInv[a]+w < distInv[b]) {
                distInv[b] = distInv[a]+w;
                q.push({-distInv[b], b});
            }
        }
    }
}

signed main() {
    fastio();
    cin >> n >> m;
    vector<tuple<int,int,int>> edges (m);
    for (auto &[a, b, c]: edges) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adjInv[b].push_back({a, c});
    }

    dijkstra();
    dijkstraInv();

    int ans = INF;
    for (auto [a, b, c]: edges) {
        int voo = dist[a] + c/2 + distInv[b];
        ans = min(ans, voo);
    }

    cout << ans << endl;
  
    return 0;
}