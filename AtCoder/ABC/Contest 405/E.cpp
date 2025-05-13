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

const int MOD = 998244353;
const int MAX_N = 4'000'005;
vi fact(MAX_N);
vi inv(MAX_N);

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = (ans*ans)%MOD;
    if (p&1) ans = (ans*b)%MOD;
    return ans;
}

int INV (int a) {
    return modpow(a, MOD-2);
}

int C(int n, int k) {
    if (n < k) return 0;
    return (((fact[n]*inv[k])%MOD) * inv[n-k])%MOD;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }
    for (int i = 0; i < MAX_N; i++) {
        inv[i] = INV(fact[i]);
    }
}

signed main() {
    fastio();
    init();
    int a, b, c, d; cin >> a >> b >> c >> d;
    int N = a+b+c+d;
    
    int ans = 0;
    for (int i = a; i <= a+b; i++) {
        ans = (ans + (C(i-1, a-1)*C(N-i, c))%MOD)%MOD; 
    }

    cout << ans << endl;
    return 0;
}