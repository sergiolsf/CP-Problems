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

const int MAXN = 800;

vi a(MAXN);
int n;
vvi memo(MAXN, vi (MAXN, -1));

int score(int i, int j, int k) {
    return a[i]*a[j]*a[k];
}

int dp(int L, int R) {
    if (R-L < 2) return 0;
    if (R-L == 2) return score(L, L+1, R);

    int &ans = memo[L][R];
    if (ans != -1) return ans;
    if (L > n) {
        ans = memo[L-n][R-n];
    }
    
    int d = 0;
    for (int i = L+1; i < R; i++) {
        d = max(d, dp(L+1, i-1)+dp(i+1, R-1)+score(L, R, i));
        d = max(d, dp(L, i)+dp(i+1, R));
    }
    d = max(d, dp(L, L)+dp(L+1, R));
    
    return ans = d;
}

void solve() {
    cin >> n;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            memo[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        a[i] = p;
        a[i+n] = p;
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, dp(i, i+n-1));
    }

    cout << ans << endl;
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