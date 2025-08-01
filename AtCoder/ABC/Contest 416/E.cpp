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

const int MAX_N = 510;
const int INF = 1'000'000'000'000'000;

int dist[MAX_N][MAX_N];

void init() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
}

signed main() {
    fastio();
    init();
    int n, m; cin >> n >> m;
    int ceu = n+1;

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }

    int sz, t; cin >> sz >> t;
    for (int i = 1; i <= sz; i++) {
        int d; cin >> d;
        dist[d][ceu] = t;
        dist[ceu][d] = 0;
    }

    for (int k = 1; k <= ceu; k++) {
        for (int i = 1; i <= ceu; i++) {
            for (int j = 1; j <= ceu; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int q; cin >> q;
    while (q--) {
        int ty; cin >> ty;

        if (ty == 1) {
            int x, y, d; cin >> x >> y >> d;

            if (dist[x][y] > d) {
                dist[x][y] = dist[y][x] = d;
                for (int i = 1; i <= ceu; i++) {
                    for (int j = 1; j <= ceu; j++) {
                        dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][x] + d + dist[y][j]);
                    }
                }

            }

        } else if (ty == 2) {
            int x; cin >> x;
            dist[x][ceu] = t;
            dist[ceu][x] = 0;

            for (int i = 1; i <= ceu; i++) {
                for (int j = 1; j <= ceu; j++) {
                    dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][x] + t + dist[ceu][j]);
                }
            }

        } else if (ty == 3) {
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cout << dist[i][j] << " ";
                    ans += (dist[i][j] < INF ? dist[i][j] : 0);
                }
                cout << endl;
            }
            cout << ans << endl << endl;    
            
        }
    }
  
    return 0;
}