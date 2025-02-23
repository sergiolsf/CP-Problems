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
    int n;
    cin >> n;
    vector<string> s(n);

    for (int i = 0; i < n; i++) cin >> s[i];

    vvi dp(n, vi(n, -1));
    vector<vvi> gRev(n, vvi(30));
    vector<vvi> g(n, vvi(30));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c = s[i][j];
            if (c != '-') {
                int ind = c - 'a';
                gRev[j][ind].push_back(i);
                g[i][ind].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != '-') {
                if (dp[i][j] == -1 || dp[i][j] > 1) {
                    dp[i][j] = 1;
                }
            }
        }
    }
    deque<pii> dq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] != -1) {
                dq.push_front({i, j});
            }
        }
    }

    while (!dq.empty()) {
        int u = dq.front().first;
        int v = dq.front().second;
        dq.pop_front();
        int d = dp[u][v];

        for (int c = 0; c < 26; c++) {
            vi X = gRev[u][c];
            vi Y = g[v][c];
            for (auto x : X) {
                for (auto y : Y) {
                    int t = d + 2;
                    if (dp[x][y] == -1 || dp[x][y] > t) {
                        dp[x][y] = t;
                        dq.push_front({x, y});
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j];
            if (j+1 < n) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
