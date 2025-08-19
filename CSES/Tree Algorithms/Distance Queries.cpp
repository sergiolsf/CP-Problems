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

int n, l;
vvi adj(MAX_N);
int timer;
vi tin, tout;
vvi up;
vi dist(MAX_N);
bool visited[MAX_N];


void dfs(int v, int p)
{
   tin[v] = ++timer;
   up[v][0] = p;
   for (int i = 1; i <= l; ++i)
       up[v][i] = up[up[v][i-1]][i-1];
   for (int u : adj[v]) {
       if (u != p)
           dfs(u, v);
   }
   tout[v] = ++timer;
}
bool is_ancestor(int u, int v)
{
   return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v)
{
   if (is_ancestor(u, v))
       return u;
   if (is_ancestor(v, u))
       return v;
   for (int i = l; i >= 0; --i) {
       if (!is_ancestor(up[u][i], v))
           u = up[u][i];
   }
   return up[u][0];
}
void preprocess(int root) {
   tin.resize(n);
   tout.resize(n);
   timer = 0;
   l = ceil(log2(n));
   up.assign(n, vector<int>(l + 1));
   dfs(root, root);
}

void dfs2 (int u, int d) {
    dist[u] = d;
    visited[u] = true;
    for (auto e: adj[u]) {
        if (visited[e]) continue;
        dfs2(e, d+1);
    }
}


signed main() {
    fastio();
    int q; cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    preprocess(0);
    dfs2(0, 0);

    while (q--) {
        int u, v; cin >> u >> v; --u; --v;
        int x = lca(u, v);
        cout << (abs(dist[x]-dist[u]) + abs(dist[x]-dist[v])) << endl;
    }
  
    return 0;
}