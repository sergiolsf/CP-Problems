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

int n, h, l, r;
vi a;
vvi memo;

int dp(int i, int ha) {
    if (i > n) return 0;
    int &ans = memo[i][ha];
    if (ans != -1) return ans;

    int d1 = 0, d2 = 0;
    if ((ha+a[i])%h >= l && (ha+a[i])%h <= r) d1++;
    if ((ha+a[i]-1)%h >= l && (ha+a[i]-1)%h <= r) d2++;

    ans = max(dp(i+1, (ha+a[i])%h) + d1, dp(i+1, (ha+a[i]-1)%h) + d2);
    return ans;
}

signed main() {
    fastio();
    cin >> n >> h >> l >> r;

    a.resize(n+1);
    memo.resize(n+1, vi (h+1, -1));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << dp(1, 0) << endl;
    
    return 0;
}