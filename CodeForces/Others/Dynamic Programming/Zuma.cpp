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

const int MAXN = 510;
const int INF = 1e18;

int n;
vi c;
vvi memo(MAXN, vi (MAXN, -1));


int dp(int i, int j) {
    if (i == j) return 1;
    if (i > j) return 0;

    int &ans = memo[i][j];
    if (ans != -1) return ans;

    int d = INF;

    for (int k = i+2; k <= j; k++) {
        if (c[k] == c[i]) d = min(d, dp(i+1, k-1)+dp(k+1, j));
    }
    d = min(dp(i+1, j) + 1, d);
    if (c[i+1] == c[i]) d = min(d, dp(i+2, j)+1);
    
    return ans = d;
}

signed main() {
    fastio();
    cin >> n;
    c.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    
    cout << dp(1, n) << endl;

    return 0;
}