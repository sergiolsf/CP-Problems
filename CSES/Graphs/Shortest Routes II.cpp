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

const int MAX_N = 505;
const int INF  = 1e18;

vvi dist(MAX_N, vi (MAX_N, INF));

signed main() {
    fastio();
    int n, m, q; cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    while (m--) {
        int a, b, c; cin >> a >> b >> c; // a - b com dist c
        dist[a][b] = dist[b][a] = min(c, dist[a][b]);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            } 
        }
    }

    while (q--) {
        int a, b; cin >> a >> b;
        if (dist[a][b] >= INF) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }
  
    return 0;
}