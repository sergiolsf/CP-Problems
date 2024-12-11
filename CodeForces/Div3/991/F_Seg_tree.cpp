#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int MAXN = 200010;
int seg[4*MAXN];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

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

    seg[pos] = gcd(seg[e], seg[d]);    
}

int query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return 0;
    if (p <= ini && fim <= q) return seg[pos];


    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return gcd(query(e, ini, m, p, q), query(d, m+1, fim, p, q));
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi v(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i < n; i++) {
        int dif = abs(v[i] - v[i+1]);
        update(1, 1, n-1, i, dif);
    }

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;

        if (l == r) cout << 0 << " ";
        else {
            cout << query(1, 1, n-1, l, r-1) << " ";
        }
    }
    cout << endl;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }    
    return 0;
}