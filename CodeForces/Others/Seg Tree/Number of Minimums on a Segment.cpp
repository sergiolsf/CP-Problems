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
const int INF = 1e10;
pii seg[4*MAXN];

void update(int pos, int ini, int fim, int id, int val) {
    if (id < ini || id > fim) return;
    if (ini == fim) {
        seg[pos] = {val, 1};
        return;
    }

    int m = (ini+fim)/2;
    int e = 2*pos, d = e+1;
    update(e, ini, m, id,val);
    update(d, m+1, fim, id, val);

    if (seg[e].first == seg[d].first) {
        seg[pos] = {seg[e].first, seg[e].second + seg[d].second};
    } else if (seg[e].first < seg[d].first) {
        seg[pos] = seg[e];
    } else {
        seg[pos] = seg[d];
    }
}

pii query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return {INF,1};
    if (p <= ini && fim <= q) return seg[pos];

    int m = (ini+fim)/2;
    int e = 2*pos, d = e+1;



    pii ans;
    pii se = query (e,ini,m,p,q);
    pii sd = query (d,m+1,fim,p,q);

    if (se.first == sd.first) {
        ans = {se.first, se.second + sd.second};
    } else if (se.first < sd.first) {
        ans = se;
    } else {
        ans = sd;
    }

    return ans;
}

signed main() {
    fastio();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        update(1, 0, n-1, i, x);
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            update(1, 0, n-1, b, c);
        } else if (a == 2) {
            pii q = query(1, 0, n-1, b, c-1);
            cout << q.first << " " << q.second << endl;
        }
    }


    
    return 0;
}