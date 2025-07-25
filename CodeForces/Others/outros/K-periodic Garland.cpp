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

const int MAX_N = 2'000'005;

int n, k; 
string s;
int sum[MAX_N];
int memo[MAX_N][3];

int ac(int i) {
    return (int) (s[i] - '0');
}

int dp(int u, int c) {
    if (u >= n) return 0;

    int &ans = memo[u][c];
    if (ans != -1) return ans;

    int d1, d2;
    if (c == 0) {
        d1 = dp(u+1, 0) + ac(u);
        d2 = dp(u+k, 1) + (1 - ac(u)) + (sum[u+k-1]-sum[u]);
    } else if (c == 1) {
        d1 = dp(u+1, 2) + ac(u);
        d2 = dp(u+k, 1) + (1 - ac(u)) + (sum[u+k-1]-sum[u]);
    } else if (c == 2) {
        return ans = dp(u+1, 2) + ac(u);
    }

    return ans = min(d1, d2);
    
}

void init() {
    sum[0] = ac(0);
    memo[0][0] = memo[0][1] = memo[0][2] = -1;
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i-1] + ac(i);
        memo[i][0] = memo[i][1] = memo[i][2] = -1;
    }
    for (int i = n; i <= 2*n; i++) sum[i] = sum[n-1];
}

void solve() {
    cin >> n >> k >> s;
    init();
    //for (int i = 0; i < n; i++) cout << sum[i] << endl;
    cout << dp(0, 0) << endl;
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