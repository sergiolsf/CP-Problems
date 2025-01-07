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

const int MAXN = 100010;
struct segmento {
    int Ai = 0, Aj = 0;
};
segmento seg[4*MAXN];

void update (int pos, int ini, int fim, int id, int val) {
    if (id < ini || id > fim) return;
    if (ini == fim) {
        seg[pos].Ai = val;
        return;
    }


    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    update(e, ini, m, id, val);
    update(d, m+1, fim, id, val);


    vi v;
    v.push_back(seg[e].Ai);   
    v.push_back(seg[e].Aj);  
    v.push_back(seg[d].Ai);  
    v.push_back(seg[d].Aj);  

    sort(all(v));

    seg[pos] = {v[3],  v[2]};
}

segmento query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return {-1,-1};
    if (p <= ini && fim <= q) return seg[pos];


    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    segmento se = query(e, ini, m, p, q), sd = query(d, m+1, fim, p, q);

    vi v;
    v.push_back(se.Ai);   
    v.push_back(se.Aj);  
    v.push_back(sd.Ai);  
    v.push_back(sd.Aj);  

    sort(all(v));

    return {v[3], v[2]};
}


signed main() {
    fastio();
    int n;
    cin >> n;
    for (int i = 1; i <= n ; i++)  {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }

    int q;
    cin >> q;

    for (int i = 1; i <= q; i++) {
        char l;
        int a, b;
        cin >> l >> a >> b;

        if (l == 'Q') {
            segmento s = query(1, 1, n, a, b);
            cout << s.Ai + s.Aj << endl;
        } else if (l == 'U') {
            update(1, 1, n, a, b);
        }
    }    
    return 0;
}