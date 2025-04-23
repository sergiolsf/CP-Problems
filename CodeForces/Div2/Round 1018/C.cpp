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

const int INF = 1e18;

int solveHor(int n, vvi& h, vi& a) {
    vvi dp(n, vi(2, INF));
    dp[0][0] = 0;
    dp[0][1] = a[0];

    for (int i = 1; i < n; i++) {
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                bool flag = true;
                for (int j = 0; j < n; j++) {
                    flag &= (h[i - 1][j] + y != h[i][j] + x);
                }
                if (flag) {
                    if (x == 0) {
                        dp[i][x] = min(dp[i][x], dp[i - 1][y]);
                    }
                    if (x == 1) {
                        dp[i][x] = min(dp[i][x], dp[i - 1][y] + a[i]);
                    }
                }
            }
        }
    }

    return min(dp[n - 1][0], dp[n - 1][1]);
}

void transp(int n, vvi& h) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(h[i][j], h[j][i]);
        }
    }
}

void solve() {
    int n; cin >> n;

    vvi h(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> h[i][j];
        }
    }

    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int horCost = solveHor(n, h, a);
    transp(n, h);
    int verCost = solveHor(n, h, b);
    int totalCost = horCost + verCost;

    if (totalCost >= INF) {
        cout << -1 << endl;
    } else {
        cout << totalCost << endl;
    }
}

signed main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
}