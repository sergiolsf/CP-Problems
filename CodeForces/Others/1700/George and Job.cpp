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

int n, m;
vi sum, p;
vvi memo;

int dp(int k, int i) {
    if (k == 0) return 0;
    if (i > n) return 0;

    int &ans = memo[k][i];
    if (ans != -1) return ans;

    if (i+m-1 <= n) {
        ans = max(dp(k-1, m+i) + (sum[m+i-1] - sum[i-1]), dp(k, i+1));
    } else ans = dp(k, i+1);

    return ans;
}

signed main() {
    fastio();
    int k;
    cin >> n >> m >> k;

    p.resize(n+1, 0);
    sum.resize(n+1, 0);
    memo.resize(k+1, vi(n+1, -1));

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i-1]+p[i];
    }

    cout << dp(k, 1) << endl;

    return 0;
}