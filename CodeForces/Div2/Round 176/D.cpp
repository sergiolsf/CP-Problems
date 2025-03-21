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

const int B = 60;
const int INF = 1e18;
vvi dp(B, vi(B, INF));

void solve() {
    int x, y; cin >> x >> y;
    int ans = INF;
    for (int i = 0; i < B; i++) {
        for (int j = 0; j < B; j++) {
            if ((x >> i) == (y >> j)) ans = min(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
}

void init() {
    dp[0][0] = 0;

    for (int x = 0; x < B; x++) {
        for (int i = B-1; i >= 0; i--) {
            for (int j = B-1; j >= 0; j--) {
                if (dp[i][j] == INF) continue;
                if (i+x < B) dp[i+x][j] = min(dp[i+x][j], dp[i][j]+(1LL << x));
                if (j+x < B) dp[i][j+x] = min(dp[i][j+x], dp[i][j]+(1LL << x));
            }
        }
    }
}

signed main() {
    fastio();
    init();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}