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
bool possible;
stack<int> ans;

vvi adj(MAX_N);
vector<bool> visited(MAX_N, false);
vector<bool> terminou(MAX_N, false);

void ordTop(int u) {
    visited[u] = true;
    for (auto v: adj[u]) {
        if (visited[v] && !terminou[v]) {
            possible = false;
        } else if (!visited[v]) {
            ordTop(v);
        }
    }
    terminou[u] = true;
    ans.push(u);
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;

    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    possible = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ordTop(i);
        }
    }

    if (!possible) cout << "IMPOSSIBLE\n";
    else {
        while (!ans.empty()) {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }
  
    return 0;
}