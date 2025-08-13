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

const int MAX_N = 1'005;

vvi adj(MAX_N);

int a, b, n, m;
int maiorDist, maiorVert;

bool visited[MAX_N];
bool setar[MAX_N];

void dfs(int u, int d) {
    visited[u] = true;
    if (maiorDist < d) {
        maiorDist = d;
        maiorVert = u;
    }

    for (auto e: adj[u]) {
        if (visited[e]) continue;
        dfs(e, d+1);
    }
}

void apaga(int u) {
    if (u == m) return;
    setar[u] = true;
    for (auto e: adj[u]) {
        if (setar[e]) continue;
        apaga(e);
    }
}

void init() {
    maiorDist = -1;
    for (int i = 0; i <= n; i++) {
        visited[i] = setar[i];
    }
}

signed main() {
    fastio();
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    m = 1;
    while (true) {
        init();
        dfs(m, 0);
        a = maiorVert;

        init();
        dfs(a, 0);
        b = maiorVert;

        if (a == b) {
            cout << "! " << m << endl;
            cout.flush();
            break;
        }

        cout << "? " << a << " " << b << endl;
        cout.flush();

        cin >> m;
        if (m == a || m == b) {
            cout << "! " << m << endl;
            cout.flush();
            break;
        }

        apaga(a);
        apaga(b);
    }

    return 0;
}