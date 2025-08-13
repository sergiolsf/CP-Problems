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
const int MOD = 1'000'000'007;

vvi adj(MAX_N);
vector<bool> visited(MAX_N, false);
stack<int> pilha;
int cnt[MAX_N];

void dfs(int u) {
    visited[u] = true;
    for (auto e: adj[u]) {
        if (visited[e]) continue;
        dfs(e);
    }
    pilha.push(u);
}

int mod (int a) {
    return (a%MOD + MOD)%MOD;
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i);
    }

    cnt[1] = 1;
    while (!pilha.empty()) {
        int u = pilha.top(); pilha.pop();
        for (auto e: adj[u]) {
            cnt[e] = mod(cnt[e]+cnt[u]);
        }
    }

    cout << cnt[n] << endl;
  
    return 0;
}