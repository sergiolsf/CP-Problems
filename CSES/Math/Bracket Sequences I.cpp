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
const int MAX_N = 1'000'005;

int fat[MAX_N];

int mod(int a) {
    return (a%MOD + MOD)%MOD;
}

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = mod(ans*ans);
    if (p&1) ans = mod(ans*b);
    return ans;
}

int inv(int a) {
    return modpow(a, MOD-2);
}

int comb(int a, int b) {
    int ans = mod(mod(fat[a]*inv(fat[b]))*inv(fat[a-b]));
    return ans;
}

void init() {
    fat[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fat[i] = mod(fat[i-1]*i);
    }
}

signed main() {
    fastio();
    init();
    int n; cin >> n;
    if (n&1) cout << 0 << endl;
    else {
        n /= 2;
        int a = comb(2*n, n);
        int b = inv(n+1);
        cout << mod(a*b) << endl;
    }

    return 0;
}