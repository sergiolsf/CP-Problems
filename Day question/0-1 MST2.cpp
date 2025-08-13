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

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    vector<set<int>> adj(n+1);

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    set<int> unvisited;
    for (int i = 1; i <= n; i++) {
        unvisited.insert(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!unvisited.count(i)) continue;
        ans++;

        queue<int> q;
        q.push(i);
        unvisited.erase(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            auto it = unvisited.begin();
            while (it != unvisited.end()) {
                int v = *it;
                if (adj[u].count(v)) {
                    ++it;
                } else {
                    it = unvisited.erase(it);
                    q.push(v);
                }
            }
        }
    }

    cout << ans-1 << endl;
  
    return 0;
}