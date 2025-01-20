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

const int MAXN = 1005;

vector<bool> visited (MAXN);
vi ans (MAXN);
vvi g (MAXN, vi (MAXN));
int n;
int k;

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = true;

    for (int i = u+1; i < n; i++) {
        if (g[u][i]) dfs(i);
    }

    ans[k] = u;
    k++;
}

void solve() {
    
    cin >> n;
    
    k = 0;

    string s;

    for (int i = 0; i < n; i++) visited[i] = false;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '0') g[i][j] = 0;
            else g[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int i = n-1; i >= 0; i--) {
        cout << ans[i]+1 << " ";
    }

    cout << endl;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}