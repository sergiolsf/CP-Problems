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

const int MAX_N = 100'005;
int seg[4*MAX_N];

int b, P, l, n; 

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
    seg[pos] = (seg[e] + seg[d])%P;
}

int query(int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return 0;
    if (p <= ini && fim <= q) return seg[pos];

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return (query(e, ini, m, p, q) + query(d, m+1, fim, p, q))%P;
}

int pot[MAX_N];

int modpow(int bb, int p) {
    if (p == 0) return 1;
    int ans = modpow(bb, p/2);
    ans = (ans*ans)%P;
    if (p&1) ans = (ans*bb)%P;
    return ans;
}

void init() {
    pot[l] = 1;
    for (int i = l-1; i >= 1; i--) {
        pot[i] = (pot[i+1]*b)%P;
    }
}

signed main() {
    fastio();
    cin >> b >> P >> l >> n;
    while (b != 0 || P != 0 || l != 0 || n != 0) {
        init();
        for (int i = 1; i <= l; i++) update(1, 1, l, i, 0);

        while (n--) {
            char c; cin >> c;
            if (c == 'E') {
                int i, v; cin >> i >> v;
                int val = (v*pot[i])%P;
                update(1, 1, l, i, val);
            } else {
                int i, j; cin >> i >> j;
                int sum = query(1, 1, l, i, j);
                //int inv = modpow(b, l-j);
                sum = (sum*modpow(pot[j], P-2))%P;
                cout << sum << endl;
            }
        }

        cout << "-\n";
        cin >> b >> P >> l >> n;
    }
  
    return 0;
}