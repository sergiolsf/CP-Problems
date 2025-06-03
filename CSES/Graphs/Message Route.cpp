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

vvi g(MAX_N);
vi dist(MAX_N, 0);
vi pai(MAX_N, 0);

void bfs (int u) {
    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        int a = q.front(); q.pop();
        for (auto e: g[a]) {
            if (dist[e] || e == u) continue;
            pai[e] = a;
            dist[e] = dist[a]+1;
            q.push(e);
        }
    }
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(1);

    if (dist[n] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dist[n]+1 << endl;
    int a = n;
    stack<int> ans;
    while (a) {
        ans.push(a);
        a = pai[a];
    }

    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }

    cout << endl;  
    return 0;
}