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

const int MOD = 1e9+7;
const int INF = 1e15;
vvi g, gT;
int n, m;
vi cost;
vi S;
vi dfs_num;
int menor, quantMenor;

void kosaraju(int u, int pass) { // pass = 1 (original), 2 (transposto)
    dfs_num[u] = 1;
    if (menor > cost[u]) {
        menor = cost[u];
        quantMenor = 1;
    } else if (menor == cost[u]) quantMenor++;

    vi &neighbor = (pass == 1) ? g[u] : gT[u];
    for (auto &v: neighbor) {
        if (dfs_num[v] == -1)
            kosaraju(v, pass);
    }
    S.push_back(u);
}

signed main() {
    fastio();

    cin >> n;
    cost.resize(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    cin >> m;
    g.resize(n+1);
    gT.resize(n+1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gT[v].push_back(u);
    }

    /// na main
    int minSum = 0, quant = 1;
    S.clear();
    dfs_num.assign(n+1, -1);
    for (int u = 1; u <= n; u++) {
        if (dfs_num[u] == -1)
            kosaraju(u, 1);
    }
    dfs_num.assign(n+1, -1);
    for (int i = n-1; i >= 0; i--) {
        if (dfs_num[S[i]] == -1) {
            menor = INF;
            quantMenor = 0;
            kosaraju(S[i], 2);
            minSum += menor;
            quant = (quant*quantMenor)%MOD;
        }
    }

    cout << minSum << " " << quant << endl;
    
    return 0;
}