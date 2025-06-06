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

const int MAXN = 200'010;
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
    seg[pos] = max(seg[e], seg[d]);    
}

int query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return -1;
    if (p <= ini && fim <= q) return seg[pos];

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return max(query(e, ini, m, p, q), query(d, m+1, fim, p, q));
}


signed main() {
    fastio();
    int n, m; cin >> n >> m;
    vi v(n+1);
    for (int i = 1; i <= n; i++) {
        int h; cin >> h;
        v[i] = h;
        update(1, 1, n, i, h);
    }

    while (m--) {
        int r; cin >> r;
        if (query(1, 1, n, 1, n) < r) {
            cout << 0 << " ";
        } else {
            int lo = 0, hi = n;
            while (hi-lo > 1) {
                int m = (hi+lo)/2;
                int u = query(1, 1, n, 1, m);
                if (u < r)  lo = m;
                else hi = m;
            }

            cout << hi << " ";
            v[hi] -= r;
            update(1, 1, n, hi, v[hi]);
        }
    }
  
    return 0;
}