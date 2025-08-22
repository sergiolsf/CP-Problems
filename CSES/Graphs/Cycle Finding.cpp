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

struct Edge {
    int u, v, w;
};

signed main() {
    fastio();
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vi dist(n+1, 0);
    vi parent(n+1, -1);
    int last_updated = -1;

    for (int i = 0; i < n; i++) {
        last_updated = -1;
        for (const Edge &e : edges) {
            if (dist[e.u] < LLONG_MAX) {
                if (dist[e.v] > dist[e.u] + e.w) {
                    dist[e.v] = dist[e.u] + e.w;
                    parent[e.v] = e.u;
                    last_updated = e.v;
                }
            }
        }
    }

    if (last_updated == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int node = last_updated;
        for (int i = 0; i < n; i++) {
            node = parent[node];
        }

        vi cycle;
        int start = node;
        cycle.push_back(start);
        node = parent[node];
        while (node != start) {
            cycle.push_back(node);
            node = parent[node];
        }
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());

        for (int i = 0; i < cycle.size(); i++) {
            cout << cycle[i] << " ";
        }
        cout << endl;
    }
  
    return 0;
}