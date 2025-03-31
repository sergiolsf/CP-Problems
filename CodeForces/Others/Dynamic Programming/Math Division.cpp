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

const int MOD = 1e9+7;
const int MAXN = 100'010;

vvi memo(MAXN, vi(5));
string s;
int n;
int inv2;

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = (ans*ans)%MOD;
    if (p&1) ans = (ans*b)%MOD;
    return ans;
}

int inv(int a) {
    return modpow(a, MOD-2);
}

int dp(int pos, int add) {
    if (pos == 0) {
        if (!add) return (n-1);
        return n;
    }

    int &ans = memo[pos][add];
    if (ans != -1) return ans;

    if (!add && s[pos] == '0') return ans = dp(pos-1, 0);
    else if (add && s[pos] == '1') return ans = dp(pos-1, 1);
    else {
            int d1 = (inv2*dp(pos-1, 0))%MOD;
            int d2 = (inv2*dp(pos-1, 1))%MOD;
            return ans = (d1+d2)%MOD;
    }
}

void reset(int a) {
    for (int i = 0; i < a; i++) {
        memo[i][0] = memo[i][1] = -1;
    }
}

void solve() {
    cin >> n;
    reset(n);
    cin >> s;
    cout << dp(n-1, 0) << endl;
}

signed main() {
    fastio();
    inv2 = inv(2);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}