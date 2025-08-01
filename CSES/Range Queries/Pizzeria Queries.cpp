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

const int INF = 1'000'000'000'000'000'000;

const int MAXN = 200'010;
int seg[4*MAXN][2];

void update (int pos, int ini, int fim, int id, int val) {
    if (id < ini || id > fim) return;
    if (ini == fim) {
        seg[pos][0] = val+id;
        seg[pos][1] = val-id;
        return;
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    update(e, ini, m, id, val);
    update(d, m+1, fim, id, val);

    seg[pos][0] = min(seg[e][0], seg[d][0]);    
    seg[pos][1] = min(seg[e][1], seg[d][1]);    
}

int query (int pos, int ini, int fim, int p, int q, int b) {
    if (q < ini || p > fim) return INF;
    if (p <= ini && fim <= q) return seg[pos][b];

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return min(query(e, ini, m, p, q, b), query(d, m+1, fim, p, q, b));
}


signed main() {
    fastio();
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        update(1, 1, n, i, p);
    }

    while (q--) {
        int op, k; cin >> op >> k;
        if (op == 1) {
            int x; cin >> x;
            update(1, 1, n, k, x);
        } else {
            int x = INF, y = INF;
            if (k-1 > 0) {
                x = query(1, 1, n, 1, k-1, 1);
            }
            if (k+1 <= n) {
                y = query(1, 1, n, k+1, n, 0);
            }
            int z = query(1, 1, n, k, k, 0) - k;
            cout << min({x+k, y-k, z}) << endl;
        }
    }
  
    return 0;
}