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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vi> grid(n+1, vi (m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    int lin = 1, col = 1;

    for (int i = 1; i <= n+m-2; i++) {
        if (s[i-1] == 'D') {
            int sum = 0;
            for (int j = 1; j <= m; j++) {
                sum += grid[lin][j];
            }
            grid[lin][col] = 0-sum;
            lin++;
        } else {
            int sum = 0;
            for (int j = 0; j <= n; j++) {
                sum += grid[j][col];
            }
            grid[lin][col] = 0 - sum;
            col++;
        }
    }

    int sum = 0;
    for (int j = 0; j <= n; j++) {
        sum += grid[j][m];
    }

    grid[n][m] = 0 - sum;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
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