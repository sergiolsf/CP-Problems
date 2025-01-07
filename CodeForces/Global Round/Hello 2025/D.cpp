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

struct node {
    int sumMax, sumMin, subMax, subMin, bestValue;
};

const int MAXN = 200010;
node seg[4*MAXN];


// pos onde estou, inicio e fim do intervalo, id que o val vai entrar
void update (int pos, int ini, int fim, int id, int val) {

    if (id < ini || id > fim) return;

    if (ini == fim) {
        seg[pos].sumMax = seg[pos].sumMin = val + ini;
        seg[pos].subMax = seg[pos].subMin = val - ini;
        seg[pos].bestValue = 0;
        return;
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    update(e, ini, m, id, val);
    update(d, m+1, fim, id, val);

    int ans1 = seg[e].sumMax - seg[d].sumMin;
    int ans2 = seg[d].subMax - seg[e].subMin;

    seg[pos].bestValue = max(ans1,ans2);

    int h = max(seg[e].bestValue, seg[d].bestValue);

    seg[pos].bestValue = max(seg[pos].bestValue, h);

    seg[pos].sumMax = max(seg[e].sumMax, seg[d].sumMax);
    seg[pos].sumMin = min(seg[e].sumMin, seg[d].sumMin);

    seg[pos].subMax = max(seg[e].subMax, seg[d].subMax);
    seg[pos].subMin = min(seg[e].subMin, seg[d].subMin);
   
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        update(1, 1, n, i, a);
    }

    cout << seg[1].bestValue << endl;

    for (int i = 1; i <= q; i++) {
        int p, x;
        cin >> p >> x;

        update(1, 1, n, p, x);

        cout << seg[1].bestValue << endl;
    }
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}