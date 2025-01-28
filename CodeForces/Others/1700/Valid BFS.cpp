#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vvi g;
vi dist, ord, pai;

signed main() {
    fastio();
    int n;
    cin >> n;

    g.resize(n+1);

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vi seq(n+1);
    seq[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
    }

    dist.resize(n+1);
    pai.resize(n+1);
    ord.resize(n+1);

    vector<bool> visited (n+1, false);

    visited[1] = true;
    queue<int> q;
    q.push(1);
    dist[1] = 1;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto e: g[v]) {
            if (!visited[e]) {
                visited[e] = true;
                q.push(e);
                dist[e] = dist[v]+1;
                pai[e] = v;
            }
        }
    }

    int lastPos, lastOrdPai;

    if (seq[1] != 1) {
        cout << "No\n";
        return 0;
    }

    ord[1] = 1;

    lastPos = 1;
    lastOrdPai = -1;

    for (int i = 2; i <= n; i++) {
        int u = seq[i];
        ord[u] = i;
        if (lastPos > dist[u]) {
            cout << "No\n";
            return 0;
        }
        lastPos = dist[u];

        if (lastOrdPai > ord[pai[u]]) {
            cout << "No\n";
            return 0;
        }

        lastOrdPai = ord[pai[u]];
    }

    sort(all(seq));

    for (int i = 1; i <= n; i++) {
        if (seq[i] != i) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    
    return 0;
}