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

const int MAX_N = 100'010;

vvi g (MAX_N);
vi num (MAX_N);
vector<bool> visited (MAX_N);
int ans;

int dfs(int u) {
    visited[u] = true;
    int r = num[u];
    int s = 0, p = 0;
    for (auto e: g[u]) {
        if (!visited[e]) {
            int c = dfs(e);
            if (c == 1) s++;
            else if (c == 2) p++;
        }
    }
    if (r == 0) {
        if (s > p) r = 1;
        else if (s < p) r = 2;
        else r = 0;
    }
    
    if (r == 1) {
        ans += p;
    } else ans += s;

    return r;
}

void solve() {
    int n; cin >> n;

    for (int i = 0; i <= n; i++) {
        visited[i] = false;
        g[i].clear();
    }

    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        g[i].push_back(a);
        g[a].push_back(i);
    }
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'C') num[i+1] = 0;
        else if (s[i] == 'S') num[i+1] = 1;
        else num[i+1] = 2;
    }

    ans = 0;
    dfs(1);
    cout << ans << endl;

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

/*
1
4
1 2 2
PPSS

*/