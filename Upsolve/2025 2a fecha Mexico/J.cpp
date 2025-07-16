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
const int MAX_N = 1'000'005;
int fat[MAX_N];
int inv[MAX_N];

int C(int a, int b) {
    int ans = (fat[a]*inv[b])%MOD;
    ans = (ans*inv[a-b])%MOD;
    return ans;
}

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = (ans*ans)%MOD;
    if (p&1) ans = (ans*b)%MOD;
    return ans;
}

void init() {
    fat[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fat[i] = (fat[i-1]*i)%MOD;
    }
    for (int i = 0; i < MAX_N; i++) {
        inv[i] = modpow(fat[i], MOD-2);
    }
}

signed main() {
    fastio();
    init();
    int q; cin >> q;
    while (q--) {
        int n, k; cin >> n >> k;
        cout << C(n+1, k+1) << endl;
    }
  
    return 0;
}