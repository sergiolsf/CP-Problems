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

int query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return INF;
    if (p <= ini && fim <= q) return seg[pos];


    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return min(query(e, ini, m, p, q), query(d, m+1, fim, p, q));
}

void build(int pos, int ini, int fim) {
    if (ini == fim) {
        seg[pos] = v[ini];
        return;
    }


    int m = (ini+fim)/2;
    int e = 2*pos, d = 2*pos+1;
    build(e, ini, m);
    build(d, m+1, fim);
    seg[pos] = min(seg[e], seg[d]);
}

signed main() {
    fastio();
    return 0;
}