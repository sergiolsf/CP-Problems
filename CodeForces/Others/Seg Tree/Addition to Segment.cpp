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

int query (int pos, int ini, int fim, int id) {
    if (id < ini || id > fim) return 0;
    if (ini == fim) {
        return seg[pos];
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    int se = query(e, ini, m, id);
    int sd = query(d, m+1, fim, id);
    
    return sd+se+seg[pos];    
}

void update (int pos, int ini, int fim, int p, int q, int v) {
    if (q < ini || p > fim) return;
    if (p <= ini && fim <= q) {
        seg[pos] += v;
        return;
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;

    update(e, ini, m, p, q, v);
    update(d, m+1, fim, p, q, v);
}


void build(int pos, int ini, int fim) {
    if (ini == fim) {
        seg[pos] = 0;
        return;
    }

    int m = (ini+fim)/2;
    int e = 2*pos, d = 2*pos+1;
    build(e, ini, m);
    build(d, m+1, fim);
    seg[pos] = 0;
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;

    build(1, 1, n);

    while(m--) {
        int p; cin >> p;
        if (p == 1) {
            int l, r, v; cin >> l >> r >> v;
            update(1, 1, n, l+1, r, v);
        } else {
            int i; cin >> i;
            cout << query(1, 1, n, i+1) << endl;
        }
    }

  
    return 0;
}