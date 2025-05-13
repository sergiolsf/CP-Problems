#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int MOD = 1'000'000'007;
const int MAX_N = 200'005;
const int MAX_S = 1024;

vi a(MAX_N);
vi p(MAX_N);
int n;

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p / 2);
    ans = (ans * ans) % MOD;
    if (p & 1) ans = (ans * b) % MOD;
    return ans;
}

int inv(int a) {
    return modpow(a, MOD - 2);
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i];

    int inv_10000 = inv(10000);
    int inv_10000_pow_n = modpow(inv_10000, n);

    vector<int> next(MAX_S);
    for (int S = 0; S < MAX_S; S++) {
        next[S] = (S * S) % MOD; 
    }

    for (int i = n; i >= 1; i--) {
        vector<int> current(MAX_S);
        for (int S = 0; S < MAX_S; S++) {
            int s_xor = S ^ a[i];
            int term1 = (p[i] * next[s_xor]) % MOD;
            int term2 = ((10000 - p[i]) * next[S]) % MOD;
            current[S] = (term1 + term2) % MOD;
        }
        next = move(current); 
    }

    int resultado = (next[0] * inv_10000_pow_n) % MOD;
    cout << resultado << endl;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}