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

const int MAXN = 200010;
int seg[4*MAXN];


int query (int pos, int ini, int fim, int id) {
    if (id < ini || id > fim) return 0;
    if (ini == fim) {
        return seg[pos];
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return seg[pos] + query(e, ini, m, id) + query(d, m+1, fim, id);
}


void update (int pos, int ini, int fim, int p, int q, int val) {
    if (q < ini || p > fim) return;
    if (p <= ini && fim <= q) {
        seg[pos] += val;
        return;
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    update(e, ini, m, p, q, val);
    update(d, m+1, fim, p, q, val);
}


signed main() {
    fastio();
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(1, 1, n, i, i, x);
    }

    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b, u; cin >> a >> b >> u;
            update(1, 1, n, a, b, u);
        } else {
            int k; cin >> k;
            cout << query(1, 1, n, k) << endl;
        }
    }
  
    return 0;
}