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

const int MAXN = 100'000;
int seg[4*MAXN];


void update (int pos, int ini, int fim, int id, int val) {
    if (id < ini || id > fim) return;
    if (ini == fim) {
        if (id%2 == 0) val = -val;
        seg[pos] = val;
        return;
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    update(e, ini, m, id, val);
    update(d, m+1, fim, id, val);
    seg[pos] = seg[e]+seg[d];    
}

int query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return 0;
    if (p <= ini && fim <= q) return seg[pos];

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return query(e, ini, m, p, q) + query(d, m+1, fim, p, q);
}

signed main() {
    fastio();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        update(1, 1, n, i, a);
    }

    int m; cin >> m;
    while(m--) {
        int p, i, j; cin >> p >> i >> j;
        if (p == 0) {
            update(1, 1, n, i, j);
        } else {
            int sum = query(1, 1, n, i, j);
            if (i%2 == 0) sum = -sum;
            cout << sum << endl;
        }
    }
  
    return 0;
}