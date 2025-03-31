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

const int MAXN = 100'010;
const int MAXS = 5;

vvi g(MAXN);
vi grupo(MAXN);
vvi team(MAXS);
vector<bool> visited(MAXN, false);

bool dfs(int u, int t) {
    visited[u] = true;
    team[t].push_back(u);
    grupo[u] = t;
    for (auto e: g[u]) {
        if (!visited[e]) dfs(e, (t+1)%2);
        else if (grupo[e] == t) return false;
    }
    return true;
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int flag = true;
    for (int i = 1; i <= n && flag; i++) {
        if (!visited[i]) {
            if(!dfs(i, 0)) flag = false;
        }
    }
    
    if (!flag) cout << "IMPOSSIVEL\n";
    else {
        cout << "POSSIVEL\n";
        int zsz = team[0].size();
        int usz = team[1].size();
        cout << zsz << " " << usz << endl;
        for (int i = 0; i < zsz; i++) cout << team[0][i] << (i == zsz-1 ? "" : " ");
        cout << endl;
        for (int i = 0; i < usz; i++) cout << team[1][i] << (i == usz-1 ? "" : " ");
        cout << endl;
    }
    return 0;
}