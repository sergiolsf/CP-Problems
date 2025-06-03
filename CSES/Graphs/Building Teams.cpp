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

vvi g(MAX_N);
vi teams(MAX_N, -1);
bool flag = true;

void dfs(int u) {
    for (auto e: g[u]) {
        if (teams[e] == -1) {
            teams[e] = (teams[u]+1)%2;
            dfs(e);
        } else if (teams[e] == teams[u]) {
            flag = false;
        }
    }
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (teams[i] == -1) {
            teams[i] = 0;
            dfs(i);
        }
    }

    if (!flag) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << teams[i]+1 << " ";
    }
    cout << endl;
  
    return 0;
}