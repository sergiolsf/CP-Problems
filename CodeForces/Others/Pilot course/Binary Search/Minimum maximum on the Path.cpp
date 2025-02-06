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

const int INF = 1e6;

int n, m, d;
vector<vector<pii>> g;

bool good (int t) {
    vi v (n+1, INF);
    for (auto e: g[1]) {
        if (e.second <= t) {
            v[e.first] = 1;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (v[i] >= d) continue;
        for (auto e: g[i]) {
            if (e.second <= t) {
                v[e.first] = min(v[i]+1, v[e.first]);
            }
        }
    }
    return v[n] <= d;
}

signed main() {
    fastio();
    cin >> n >> m >> d;

    g.resize(n+1);

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
    }

    /// testa se a resposta é -1

    int l = 0;
    int r = 1;
    while (!good(r)) { 
        if (r >= 1e10) {
            cout << -1 << endl;
            return 0;
        }
        r *= 2;
    }

    while (r-l != 1) {
        int m = (r+l)/2;
        if (good(m)) r = m;
        else l = m;
    }

    if (good(0)) r = 0;

    vector<pii> v (n+1, {INF,0});
    for (auto e: g[1]) {
        if (e.second <= r) {
            v[e.first] = {1,1};
        }
    }
    for (int i = 2; i <= n; i++) {
        if (v[i].first >= d) continue;
        for (auto e: g[i]) {
            if (e.second <= r) {
                if (v[e.first].first > v[i].first+1) {
                    v[e.first].first = v[i].first+1;
                    v[e.first].second = i;
                }
            }
        }
    }

    vi ans;
    int u = n;

    while (u != 0) {
        ans.pb(u);
        u = v[u].second;
    }

    cout << ans.size()-1 << endl;
    for (int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
    cout << endl;

    return 0;
}