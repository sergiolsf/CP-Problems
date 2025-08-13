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
const int MAX = 200'005;

int inv[MAX];

namespace seg {
    int seg[4*MAX], lazy[4*MAX];
    int n, *v;

    int build(int p=1, int l=0, int r=n-1) {
        lazy[p] = -1;
        if (l == r) return seg[p] = v[l];
        int m = (l+r)/2;
        return seg[p] = (build(2*p, l, m) + build(2*p+1, m+1, r)) % MOD;
    }

    void build(int n2, int* v2) {
        n = n2, v = v2;
        build();
    }

    void prop(int p, int l, int r) {
        if (lazy[p] == -1) return;
        seg[p] = (1LL * lazy[p] * (r - l + 1)) % MOD;
        if (l != r) {
            lazy[2*p] = lazy[p];
            lazy[2*p+1] = lazy[p];
        }
        lazy[p] = -1;
    }

    int query(int a, int b, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (a <= l && r <= b) return seg[p];
        if (b < l || r < a) return 0;
        int m = (l+r)/2;
        return (query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r)) % MOD;
    }

    int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
        prop(p, l, r); 
        if (a <= l && r <= b) {
            seg[p] = (1LL * x * (r - l + 1)) % MOD;
            if (l != r) {
                lazy[2*p] = x;
                lazy[2*p+1] = x;
            }
            return seg[p];
        }
        if (b < l || r < a) return seg[p];
        int m = (l+r)/2;
        return seg[p] = (update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r)) % MOD;
    }
};

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = (ans*ans)%MOD;
    if (p&1) ans = (ans*b)%MOD;
    return ans;
}

void init() {
    for (int i = 0; i < MAX; i++) {
        inv[i] = modpow(i, MOD-2);
    }
}

signed main() {
    init();
    fastio();
    int n, m; cin >> n >> m;
    int v[n];

    for (auto &i: v) cin >> i;

    seg::build(n, v);

    while (m--) {
        int l, r; cin >> l >> r;
        int sum = seg::query(l-1, r-1);
        int x = (sum*inv[r-l+1])%MOD;
        seg::update(l-1, r-1, x);
    }

    for (int i = 0; i < n; i++) {
        cout << seg::query(i,i) << (i == n-1 ? "\n" : " ");
    }

    
    return 0;
}