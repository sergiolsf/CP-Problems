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

void solve() {
    int n;
    cin >> n;

    vvi g(n+1);
    vi deg(n+1, 0);

    multiset<int> ms;

    int ans = 0;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= n; i++) {
        ms.insert(deg[i]);
    }

    for (int i = 1; i <= n; i++) {
        ms.erase(deg[i]);
        for (auto e: g[i]) {
            int u = deg[e];
            ms.erase(u);
            ms.insert(u-1);
        }

        auto k = ms.end();
        k--;
        //k--;

        ans = max(ans, deg[i] + *k - 1);

        ms.insert(deg[i]);
        for (auto e: g[i]) {
            int u = deg[e];
            ms.erase(u-1);
            ms.insert(u);
        }
    }

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