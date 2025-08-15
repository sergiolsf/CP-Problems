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

vvi adj(MAX_N);

vector<bool> visitedAbaixo(MAX_N);
vi distAbaixo(MAX_N);
vi nohsAbaixo(MAX_N);

vector<bool> visitedTotal(MAX_N);
vi nohsTotal(MAX_N);
vi distTotal(MAX_N);

pii dfsAbaixo(int u) {
    visitedAbaixo[u] = true;
    int noh = 0, dist = 0;
    for (auto e: adj[u]) {
        if (visitedAbaixo[e]) continue;
        auto [n, d] = dfsAbaixo(e);
        noh += n; dist += d;
    }

    dist += noh;
    distAbaixo[u] = dist;
    nohsAbaixo[u] = noh;

    return {noh+1, dist};
}

void dfsTotal(int u, int distAcima, int nohsAcima) {
    visitedTotal[u] = true;

    int nohs = nohsAbaixo[u];
    distTotal[u] = distAbaixo[u];
    if (u != 1) {
        distTotal[u] = distAbaixo[u] + distAcima - (distAbaixo[u] + nohsAbaixo[u] + 1) + (nohsAcima - nohsAbaixo[u]);
        nohs = nohsAcima;
    }   

    for (auto e: adj[u]) {
        if (visitedTotal[e]) continue;
        dfsTotal(e, distTotal[u], nohs);
    }
}

signed main() {
    fastio();
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 1º DFS para achar a quantidade de nós e dist abaixo
    dfsAbaixo(1);

    // 2º DFS para achar a distancia total
    dfsTotal(1, 0, 0);

    for (int i = 1; i <= n; i++) cout << distTotal[i] << (i == n ? "\n" : " ");
  
    return 0;
}