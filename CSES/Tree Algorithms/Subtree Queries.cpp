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

const int MAXN = 400'010;
const int MAX_NOH = 200'010;

int n;
int seg[4*MAXN];
int v[MAX_NOH];
vvi adj(MAX_NOH);
int k = 0;
int in_noh[MAX_NOH];
int out_noh[MAX_NOH];
bool visited[MAX_NOH];

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
    seg[pos] = seg[e]+seg[d];    
}

int query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return 0;
    if (p <= ini && fim <= q) return seg[pos];

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return query(e, ini, m, p, q) + query(d, m+1, fim, p, q);
}


void euler_tour (int u) {
    visited[u] = true;
    in_noh[u] = ++k;
    update(1, 1, 2*n, k, v[u]);
    for (auto e: adj[u]) {
        if (visited[e]) continue;
        euler_tour(e);
    }
    out_noh[u] = ++k;
    update(1, 1, 2*n, k, v[u]);
}

signed main() {
    fastio();
    int q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    euler_tour(1);

    while (q--) {
        int op, s; cin >> op >> s;
        if (op == 1) {
            int x; cin >> x;
            update(1, 1, 2*n, in_noh[s], x);
            update(1, 1, 2*n, out_noh[s], x);
        } else {
            int sum = query(1, 1, 2*n, in_noh[s], out_noh[s]);
            cout << sum/2 << endl;
        }
    }

  
    return 0;
}