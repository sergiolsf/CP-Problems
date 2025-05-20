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

int n, k, maiorDist; 
int v[MAX_N];
int cont[MAX_N];
int dist[MAX_N];
bool visited[MAX_N];
vvi g;

bool dfs (int u) {
    visited[u] = true;

    int ans = 0;
    for (auto w: g[u]) {
        if (visited[w]) continue;
        dist[w] = dist[u]+1;
        bool d = dfs(w);
        if (d) ans += cont[w]+1;
    }

    cont[u] = ans;
    if (ans > 0 || v[u] > k) {
        maiorDist = max(maiorDist, dist[u]);
        return true;
    }
    return false;
}

signed main() {
    fastio();
    cin >> n >> k;

    g.resize(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool d = dfs(1);

    cout << cont[1]*2 - maiorDist << endl;
    
    return 0;
}