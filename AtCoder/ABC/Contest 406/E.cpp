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

int ans;
int s[62][62];
int f[62][62];
int fat[62];

int mod(int m) {
    return (m%MOD + MOD)%MOD;
}

int maxPot(int n) {
    int cont = 0;
    while (n) {
        n /= 2;
        cont++;
    }
    return cont-1;
}

int cont(int n, int k) {
    if (n <= 0 || k == 0) return 0;
    
    int x = maxPot(n);
    int F = 0;
    if (k > 0) {
        ans = mod(ans+s[x][k]);
        F = f[x][k];
    }
    int c = cont(n-(1LL<<x), k-1);
    int a = mod(mod(1LL << n) * c);
    ans = mod(ans+a);
    return mod(c+F);
}

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = mod(ans*ans);
    if (p&1) ans = mod(ans*b);
    return ans;
}

int inv (int a) {
    return modpow(a, MOD-2);
}

int C(int a, int b) {
    return mod(mod(fat[a]*inv(fat[b]))*inv(fat[a-b]));
}

void init() {
    fat[0] = 1;
    for (int i = 1; i <= 60; i++) {
        fat[i] = mod(fat[i-1]*i);
    }

    for (int i = 0; i < 60; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                f[i][j] = 1;
                s[i][j] = 0;
                continue;
            }
            f[i][j] = C(i, j);
            s[i][j] = mod(C(i-1, j-1)*mod(((1LL<<i) - 1)));
        }
    }
}

signed main() {
    fastio();
    init();
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        ans = 0;
        cont(n, k);
        cout << ans << endl;
    }
  
    return 0;
}