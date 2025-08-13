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

const int MAX = 200'005;

// soma : 0
// substitui: 1

namespace seg {
	int seg[4*MAX], lazy[2][4*MAX];
	int n, *v;

	int build(int p=1, int l=0, int r=n-1) {
		lazy[0][p] = 0;
		lazy[1][p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}

	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}

	void prop(int p, int l, int r, int ind) {
        if (ind) {
            if (lazy[ind][p] == -1) return;
            seg[p] = lazy[ind][p]*(r-l+1);
		    if (l != r) lazy[ind][2*p] = lazy[ind][p], lazy[ind][2*p+1] = lazy[ind][p];
		    lazy[ind][p] = -1;
        } else {
            seg[p] += lazy[ind][p]*(r-l+1);
		    if (l != r) lazy[ind][2*p] += lazy[ind][p], lazy[ind][2*p+1] += lazy[ind][p];
		    lazy[ind][p] = 0;
        }
	}

	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r, 0);
		prop(p, l, r, 1);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}

	int updateSoma(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r, 0);
		prop(p, l, r, 1);
		if (a <= l and r <= b) {
			lazy[0][p] += x;
			prop(p, l, r, 1);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = updateSoma(a, b, x, 2*p, l, m) +
			updateSoma(a, b, x, 2*p+1, m+1, r);
	}
};

signed main() {
    fastio();
    int n, q; cin >> n >> q;
    int v[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    seg::build(n, v);

    while (q--) {
        int op, a, b; cin >> op >> a >> b;
        if (op == 1) {
            int x; cin >> x;

        } else if (op == 2) {
            int x; cin >> x;

        } else {

        }
    }
  
    return 0;
}