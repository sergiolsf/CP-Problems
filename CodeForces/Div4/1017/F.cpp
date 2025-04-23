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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vvi grid (n+1, vi (m+1));
    int q = 1;
    if (n >= m) {
        if (n%k != 0) {
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    grid[j][i] = q;
                    q++;
                    if (q == k+1) q = 1;
                }
            }
        } else {
            int ini = 1;
            for (int i = 1; i <= m; i++) {
                q = ini;
                for (int j = 1; j <= n; j++) {
                    grid[j][i] = q;
                    q++;
                    if (q == k+1) q = 1;
                }
                ini++;
                if (ini > k) ini = 1;
            }
        }
    } else {
        if (m%k != 0) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    grid[i][j] = q;
                    q++;
                    if (q == k+1) q = 1;
                }
            }
        } else {
            int ini = 1;
            for (int i = 1; i <= n; i++) {
                q = ini;
                for (int j = 1; j <= m; j++) {
                    grid[i][j] = q;
                    q++;
                    if (q == k+1) q = 1;
                }
                ini++;
                if (ini > k) ini = 1;
            }
        }
        
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << grid[i][j] << (j == m ? "\n" : " ");
        }
    }
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