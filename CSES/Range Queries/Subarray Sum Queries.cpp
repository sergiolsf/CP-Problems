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
    int maxSS = 0, maxR = 0, maxL = 0, sumTot = 0; 
};

node nulo;

const int MAX_N = 200'010;
node seg[4*MAX_N];

void update (int pos, int ini, int fim, int id, int val) {
    if (id < ini || id > fim) return;
    if (ini == fim) {
        seg[pos].maxL = seg[pos].maxR = seg[pos].maxSS = max(val, 0LL);
        seg[pos].sumTot = val;
        return;
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    update(e, ini, m, id, val);
    update(d, m+1, fim, id, val);

    seg[pos].maxSS = max({seg[d].maxSS, seg[e].maxSS, seg[e].maxR + seg[d].maxL, 0LL});
    seg[pos].maxL = max({seg[e].maxL, seg[e].sumTot+seg[d].maxL, seg[e].sumTot+seg[d].sumTot, 0LL}); 
    seg[pos].maxR = max({seg[d].maxR, seg[d].sumTot+seg[e].maxR, seg[e].sumTot+seg[d].sumTot, 0LL}); 
    seg[pos].sumTot = seg[e].sumTot + seg[d].sumTot;
}

signed main() {
    fastio();
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(1, 1, n, i, x);
    }

    while (q--) {
        int k, x; cin >> k >> x;
        update(1, 1, n, k, x);
        cout << seg[1].maxSS << endl;
    }
  
    return 0;
}