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

const int MAXN = 400010;
int seg[4*MAXN];

void update (int pos, int ini, int fim, int id, int val) {
    if (id < ini || id > fim) return;
    if (ini == fim) {
        seg[pos] = val;
        return;
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    update(e, ini, m, id, val);
    update(d, m+1, fim, id, val);
    seg[pos] = __gcd(seg[e], seg[d]);    
}


int query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return 0;
    if (p <= ini && fim <= q) return seg[pos];

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return __gcd(query(e, ini, m, p, q), query(d, m+1, fim, p, q));
}

void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;

    int g = 0;
    for (int i = 1; i <= n; i++) {
        update(1, 1, 2*n, i, a[i-1]);
        update(1, 1, 2*n, i+n, a[i-1]);
        g = __gcd(g, a[i-1]);
    }

    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        int x = a[i-1];
        if (x == g) continue;
        int l = i; // gcd != g
        int r = i+n; // gcd = g
        while (r-l != 1) {
            int m = (r+l)/2;
            if (query(1, 1, 2*n, i, m) == g) r = m;
            else l = m;
        }
        ans = max(ans, r-i);
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