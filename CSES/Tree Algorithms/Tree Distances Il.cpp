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
int maiorDist1[MAX_N];
int vertDist1[MAX_N];
int maiorDist2[MAX_N];
bool visited[MAX_N];
bool visited2[MAX_N];

int dfs(int u) {
    visited[u] = true;

    int dist1 = 0, vert1 = 0;
    int dist2 = 0;

    for (auto e: adj[u]) {
        if (visited[e]) continue;
        int d = dfs(e);
        if (d > dist1) {
            swap(dist1, dist2);
            dist1 = d;
            vert1 = e;
        } else if (d > dist2) {
            dist2 = d;
        }
    }

    maiorDist1[u] = dist1;
    maiorDist2[u] = dist2;
    vertDist1[u] = vert1;

    return dist1+1;
}

void dfsPai(int u, int dist) {
    visited2[u] = true;

    if (dist > maiorDist1[u]) {
        maiorDist1[u] = dist;
        vertDist1[u] = 0;
    } else if (dist > maiorDist2[u]) {
        maiorDist2[u] = dist;
    }

    for (auto e: adj[u]) {
        if (visited2[e]) continue;

        if (vertDist1[u] != e) {
            dfsPai(e, maiorDist1[u]+1);
        } else {
            dfsPai(e, maiorDist2[u]+1);
        }
    }
}

signed main() {
    fastio();
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    dfsPai(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << maiorDist1[i] << (i == n ? "\n" : " ");
    }
  
    return 0;
}