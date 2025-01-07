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

const int MAXN = 300010;
bool seg[4*MAXN];

void update (int pos, int ini, int fim, int id) {
    if (id < ini || id > fim) return;
    if (ini == fim) {
        seg[pos] = true;
        return;
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    update(e, ini, m, id);
    update(d, m+1, fim, id);

    seg[pos] = (seg[e] && seg[d]);    
}

bool query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return true;
    if (p <= ini && fim <= q) return seg[pos];

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return (query(e, ini, m, p, q) && query(d, m+1, fim, p, q));
}

void solve() {
    memset(seg, false, sizeof(seg));
    int n;
    cin >> n;
    vector<pii> a(n+1);
    map<int,int> mp;

    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;

        a[i] = {l,r};

        if (l == r) {
            if (mp.count(l)) {
                mp[l]++;
            } else {
                update(1, 1, 2*n+1, l);
                mp[l] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int l = a[i].first, r = a[i].second;

        if (l == r) {
            if (mp[l] == 1) {
                cout << 1;
            } else {
                cout << 0;
            }
        } else {
            if (query(1, 1, 2*n+1, l, r)) {
                cout << 0;
            } else {
                cout << 1;
            }
        }

    }

    cout << endl;
    
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