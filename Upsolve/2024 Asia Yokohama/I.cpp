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

const int MAX_N = 100'005;

int f[MAX_N];
int s[MAX_N];

vi divisores(int n) {
    vi ans;
    for (int i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            ans.push_back(i);
            if (i*i != n) ans.push_back(n/i);
        }
    }
    return ans;
}

int seg[4*MAX_N];

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
    seg[pos] = max(seg[e], seg[d]);    
}

int query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return -1;
    if (p <= ini && fim <= q) return seg[pos];

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return max(query(e, ini, m, p, q), query(d, m+1, fim, p, q));
}


void init() {
    for (int i = 0; i < MAX_N; i++) {
        f[i] = -1;
        s[i] = -1;
    }
}

signed main() {
    fastio();
    init();
    int n; cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;
    int q; cin >> q;
    vi ans(q);
    vector<tuple<int, int, int>> vp(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        auto &[a, b, c] = vp[i];
        a = r; b = l; c = i;
    }
    sort(all(vp));

    int j = 0;
    for (int i = 0; i < n; i++) {
        vi div = divisores(a[i]);
        for (auto d: div) {
            swap(f[d], s[d]);
            f[d] = i+1;
            update(1, 1, MAX_N-1, d, s[d]);
        }

        auto [r, l, pos] = vp[j];
        while (r == i+1) {
            int hi = MAX_N-1, lo = 1;
            while (hi-lo > 1) {
                int m = (hi+lo)/2;
                if (query(1, 1, MAX_N-1, m, hi) >= l) lo = m;
                else hi = m;
            }
            ans[pos] = lo;
            j++;
            auto [a, b, c] = vp[j];
            r = a; l = b; pos = c;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

  
    return 0;
}