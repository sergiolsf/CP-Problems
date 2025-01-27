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

signed main() {
    fastio();
    int n, m;
    cin >> n >> m;

    vvi g(n+1, vi ((1<<n) + 1));

    for (int i = 1; i <= (1<<n); i++) {
        cin >> g[0][i];
    }

    for (int i = 1; i <= n; i++) {
        if (i%2 == 0) {
            for (int j = 1; j <= (1 << (n-i)); j++) {
                g[i][j] = g[i-1][2*j-1] ^ g[i-1][2*j];
            }
        } else {
            for (int j = 1; j <= (1 << (n-i)); j++) {
                g[i][j] = g[i-1][2*j-1] | g[i-1][2*j];
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int p, b;
        cin >> p >> b;
        g[0][p] = b;

        int j = p;

        for (int i = 1; i <= n; i++) {
            j = (j+1)/2;
            if (j < 1) j = 1;
            if (i%2 == 0) {
                g[i][j] = g[i-1][2*j-1] ^ g[i-1][2*j];
            } else {
                g[i][j] = g[i-1][2*j-1] | g[i-1][2*j];
            }
        }

        cout << g[n][1] << endl;
    }
    
    return 0;
}