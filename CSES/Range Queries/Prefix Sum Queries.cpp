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

struct node {
    int sum = 0, pref = 0;
};

const int MAXN = 200'010;
node seg[4*MAXN];
node nulo;

void update (int pos, int ini, int fim, int id, int val) {
    if (id < ini || id > fim) return;
    if (ini == fim) {
        seg[pos].sum = seg[pos].pref = val;
        return;
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    update(e, ini, m, id, val);
    update(d, m+1, fim, id, val);

    seg[pos].sum = seg[e].sum + seg[d].sum;
    seg[pos].pref = max(seg[e].pref, seg[e].sum + seg[d].pref);    
}

node query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return nulo;
    if (p <= ini && fim <= q) return seg[pos];

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    node ne = query(e, ini, m, p, q);
    node nd = query(d, m+1, fim, p, q);
    node ans;
    ans.sum = ne.sum + nd.sum;
    ans.pref = max(ne.pref, ne.sum + nd.pref);
    return ans;
}

signed main() {
    fastio();
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(1, 1, n, i, x);
    }
    while (q--) {
        int op, a, b; cin >> op >> a >> b;
        if (op == 1) {
            update(1, 1, n, a, b);
        } else {
            node ans = query(1, 1, n, a, b);
            cout << max(0LL, ans.pref) << endl;
        }
    }
  
    return 0;
}