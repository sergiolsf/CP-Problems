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

signed main() {
    fastio();
    int t, k;
    cin >> t >> k;

    vi dp(1e5+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= 1e5+1; i++) {
        dp[i] = dp[i-1];
        if (i >= k) dp[i] = (dp[i-k]+dp[i])%MOD; 
    }

    vi sum(1e5+1, 0);

    for (int i = 1; i <= 1e5+1; i++) {
        sum[i] = (dp[i] + sum[i-1])%MOD;
    }

    for (int i = 1; i <= t; i++) {
        int a, b;
        cin >> a >> b;
        cout << ((sum[b] - sum[a-1])+MOD)%MOD << endl;
    }

    
    return 0;
}