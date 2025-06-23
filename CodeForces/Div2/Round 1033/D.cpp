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

const int MOD = 1'000'000'007;
const int MAX_N = 100'005;

int fat[MAX_N];
int inv[MAX_N];

int mod(int a) {
    return (a%MOD + MOD)%MOD;
}

int choose(int n, int k) {
    if (n < k) return 0;
    return mod(mod(fat[n]*inv[k])*inv[n-k]);
}

void solve() {
    int a, b, k; cin >> a >> b >> k;
    int n = mod(k*(a-1)+1);
    int m = mod(mod(mod((b-1)*k)*choose(n, a))+1);
    cout << n << " " << m << endl;
}

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = mod(ans*ans);
    if (p&1) ans = mod(ans*b);
    return ans;
}

void init() {
    fat[0] = 1;
    for (int i = 1; i < MAX_N; i++) fat[i] = mod(fat[i-1]*i);
    for (int i = 0; i < MAX_N; i++) inv[i] = modpow(fat[i], MOD-2);
}

signed main() {
    fastio();
    init();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}