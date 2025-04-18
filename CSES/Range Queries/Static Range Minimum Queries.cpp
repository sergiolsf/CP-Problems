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
const int INF = 1e10;


// pos onde estou, inicio e fim do intervalo, id que o val vai entrar
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


    seg[pos] = min(seg[e], seg[d]);    
}


// pos noh que estou,ini e fim é o intervalo que pos representa
// p e q é o intervalo que quero calcular o mínimo
int query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return INF;
    if (p <= ini && fim <= q) return seg[pos];


    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return min(query(e, ini, m, p, q), query(d, m+1, fim, p, q));
}


signed main() {
    fastio();
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }

    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << endl;
    }
    
    return 0;
}
