#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int lig;

const int MAX = 1'000'005;

namespace seg {
	ll seg[4*MAX];
    bool lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = false;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		lig = build();
	}
	void prop(int p, int l, int r) {
        if (lazy[p]) {
            seg[p] = (r-l+1)-seg[p];
        }
		if (l != r) lazy[2*p] ^= lazy[p], lazy[2*p+1] ^= lazy[p];
		lazy[p] = false;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}

	ll update(int a, int b, int x = true, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] ^= x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

///

const int INF = 1'000'000'000'000'000;

signed main() {
    fastio();
    int tot = 0, sum = 0;
    int n, m; cin >> n >> m;
    int j = 0;
    map<int,int> mp;
    int w[MAX];
    for (int i = 0; i < n; i++) {
        int s, p; cin >> s >> p;
        sum += p;
        if (s != -1) {
            mp[i] = j;
            w[tot] = s;
            tot++;
            j++;
        }        
    }

    mp[INF] = INF;

    seg::build(tot, w);

    while (m--) {
        char op; cin >> op;
        if (op == 'W') {
            int l, r; cin >> l >> r;

            int L, R;
            L = mp.lower_bound(l)->first;
            R = mp.lower_bound(r)->first;
            if (R > r) R = (--mp.lower_bound(r))->first;
            
            if (L > r || R < l || R < L) continue;

            l = mp[L];
            r = mp[R];
            
            seg::update(l, r, 1);
            lig = seg::query(0, tot-1);
            
        } else {
            int q; cin >> q;
            
            sum += q*lig;
        }
    }

    cout << sum << endl;
  
    return 0;
}