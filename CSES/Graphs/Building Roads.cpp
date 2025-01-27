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

vector<bool> visited;
vvi g;

void dfs (int u) {
    visited[u] = true;
    for (auto e: g[u]) {
        if (!visited[e]) dfs(e);
    }
}

signed main() {
    fastio();
    int n, m;
    cin >> n >> m;

    visited.resize(n+1, false);
    g.resize(n+1);    

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vi con(n+1);
    int cc = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cc++;
            dfs(i);
            con[cc] = i;
        }
    }

    cout << cc-1 << endl;

    if (cc > 1) {
        for (int i = 2; i <= cc; i++) {
            cout << con[1] << " " << con[i] << endl;
        }
    }

    
    return 0;
}