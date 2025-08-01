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

int n, m; 
vvi adj(MAX_N);
bool queries[MAX_N];
bool visited[MAX_N];
vvi noh(MAX_N);
vi qntquery(MAX_N);

void solve (int u) {
    visited[u] = true;
    vi v;
    for (auto e: adj[u]) {
        if (visited[e]) continue;
        for (auto q: noh[e]) v.push_back(q);
    }

    for (auto e: v) {
        qntquery[e]--;
        if (qntquery[e] == 0) queries[e] = true;
    }

    for (auto e: adj[u]) {
        if (visited[e]) continue;
        solve(e);
    }

    for (auto e: v) {
        qntquery[e]++;
    }
}

signed main() {
    fastio();
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= m; i++) {
        int k; cin >> k;
        qntquery[i] = k;

        while (k--) {
            int a; cin >> a;
            if (a == 1) {
                qntquery[i]--;
                continue;
            }
            noh[a].push_back(i);
        }
        if (qntquery[i] == 0) queries[i] = true;
    }

    solve(1);

    for (int i = 1; i <= m; i++) {
        cout << (queries[i] ? "YES\n" : "NO\n");
    }

    return 0;
}