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

const int MOD = 1e9+7;

int n, m;
vi x;

vvi memo;

int dp (int ind, int ant) {
    if (ind > n) return 1;
    if (memo[ind][ant] != -1) return memo[ind][ant];
    if (x[ind] != 0) {
        if (abs(ant - x[ind]) > 1) {
            return memo[ind][ant] = 0;
        }
        return memo[ind][ant] = dp(ind+1, x[ind]);
    } else {
        int ans = 0;
        if (ant-1 >= 1) ans = (dp(ind+1, ant-1) + ans)%MOD;
        if (ant+1 <= m) ans = (dp(ind+1, ant+1) + ans)%MOD;
        ans = (dp(ind+1, ant) + ans)%MOD;
        memo[ind][ant] = ans;
        return ans;
    }
}

signed main() {
    fastio();
    
    cin >> n >> m;

    x.resize(n+1);
    memo.resize(n+1, vi(m+1, -1));

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    if (x[1]) {
        cout << dp(1, x[1]) << endl;
    } else {
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans = (ans + dp(2, i))%MOD;
        }
        cout << ans << endl;
    }
    
    return 0;
}