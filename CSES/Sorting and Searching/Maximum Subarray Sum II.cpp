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
    int sum = 0, maxSumDir = 0;
};

const int MAXN = 200010;
node seg[4*MAXN];

node nulo;

void update (int pos, int ini, int fim, int id, int val) {
    if (id < ini || id > fim) return;
    if (ini == fim) {
        seg[pos].maxSumDir = max(val, 0LL);
        seg[pos].sum = val;
        return;
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    update(e, ini, m, id, val);
    update(d, m+1, fim, id, val);
    seg[pos].sum = seg[e].sum + seg[d].sum;    
    seg[pos].maxSumDir = max(seg[d].maxSumDir, seg[d].sum + seg[e].maxSumDir);
}

node query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return nulo;
    if (p <= ini && fim <= q) return seg[pos];

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;

    node nd = query(d, m+1, fim, p, q);
    node ne = query(e, ini, m, p, q);
    node nn;

    nn.sum = nd.sum + ne.sum;    
    nn.maxSumDir = max(nd.maxSumDir, nd.sum + ne.maxSumDir);
    return nn;
}


signed main() {
    fastio();
    int n, a, b; cin >> n >> a >> b;

    vi v(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        update(1, 1, n, i, v[i]);
    }

    int suma = 0;
    for (int i = 1; i < a; i++) {
        suma += v[i];
    }

    int ans = -1'000'000'000'000'000'000;
    for (int i = a; i <= n; i++) {
        suma -= v[i-a];
        suma += v[i];

        int res = suma;
        if (i-a >= 1) {
            int p = max(1LL, i-a-(b-a)+1), q = i-a;
            res += query(1, 1, n, p, q).maxSumDir;        
        }

        ans = max(ans, res);
    }

    cout << ans << endl;    
  
    return 0;
}