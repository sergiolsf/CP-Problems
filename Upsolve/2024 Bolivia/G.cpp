#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int MAX = 100'005;
const int MAX_N = 10'005;

//const int MAX = 100;
//const int MAX_N = 100;

ll vg[MAX];
int mdp[MAX_N];
int sum[MAX_N];

int somadiv (int x) {
    int ans = 0;
    while (x != 1) {
        ans += mdp[x];
        x /= mdp[x];
    }
    return ans;
}

namespace seg {
	ll segsoma[4*MAX], lazysoma[4*MAX], lazypos[4*MAX], segpos[4*MAX];
	int n, *v;

	ll buildsoma(int p=1, int l=0, int r=n-1) {
		lazysoma[p] = -1;
		if (l == r) return segsoma[p] = sum[v[l]];
		int m = (l+r)/2;
		return segsoma[p] = buildsoma(2*p, l, m) + buildsoma(2*p+1, m+1, r);
	}
    void buildpos(int p=1, int l=0, int r=n-1) {
		lazypos[p] = 0;
		if (l == r) {
            segpos[p] = v[l];
            return;
        }
		int m = (l+r)/2;
		buildpos(2*p, l, m);
        buildpos(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		buildsoma();
		buildpos();
	}


    ///
	void propsoma(int p, int l, int r) {
        if (lazysoma[p] != -1) {
            segsoma[p] = lazysoma[p]*(r-l+1);
            if (l != r) lazysoma[2*p] = lazysoma[p], lazysoma[2*p+1] = lazysoma[p];
        }
		lazysoma[p] = -1;
	}
	ll querysoma(int a, int b, int p=1, int l=0, int r=n-1) {
		propsoma(p, l, r);
		if (a <= l and r <= b) return segsoma[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return querysoma(a, b, 2*p, l, m) + querysoma(a, b, 2*p+1, m+1, r);
	}
	ll updatesoma(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		propsoma(p, l, r);
		if (a <= l and r <= b) {
			lazysoma[p] = x;
			propsoma(p, l, r);
			return segsoma[p];
		}
		if (b < l or r < a) return segsoma[p];
		int m = (l+r)/2;
		return segsoma[p] = updatesoma(a, b, x, 2*p, l, m) +
			updatesoma(a, b, x, 2*p+1, m+1, r);
	}
    ///
    void proppos(int p, int l, int r) {
        if (lazypos[p]) {
            segpos[p] = lazypos[p];
            if (l != r) lazypos[2*p] = lazypos[p], lazypos[2*p+1] = lazypos[p];
        }
		lazypos[p] = 0;
	}
	ll querypos(int a, int b, int p=1, int l=0, int r=n-1) {
		proppos(p, l, r);
		if (a <= l and r <= b) return segpos[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return querypos(a, b, 2*p, l, m) + querypos(a, b, 2*p+1, m+1, r);
	}
	void updatepos(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		proppos(p, l, r);
		if (a <= l and r <= b) {
			lazypos[p] = x;
			proppos(p, l, r);
			return;
		}
		if (b < l or r < a) return;
		int m = (l+r)/2;
		updatepos(a, b, x, 2*p, l, m);
		updatepos(a, b, x, 2*p+1, m+1, r);
	}
};

void init() {
    mdp[1] = 1;
    mdp[0] = 1;
    for (int i = 2; i < MAX_N; i++) {
        if (mdp[i] == 0) {
            for (int j = i; j < MAX_N; j += i) {
                mdp[j] = i;
            }
        }
    }
    sum[0] = 1;
    sum[1] = 0;
    for (int i = 2; i < MAX_N; i++){
        sum[i] = somadiv(i);
    }
}


signed main() {
    fastio();
    init();
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> vg[i];
    seg::build(n, vg);
    int q; cin >> q;
    int j = 0;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; cin >> i;
            i--;
            int x = seg::querypos(i, i);
            int y = x/mdp[x];
            j++;
            seg::updatepos(i, i, y);
            seg::updatesoma(i, i, sum[y]);     
        } else if (t == 2) {
            int l, r; cin >> l >> r;
            l--; r--;
            cout << seg::querysoma(l, r) << endl;
        } else {
            int l, r, x; cin >> l >> r >> x;
            l--; r--;
            seg::updatesoma(l, r, sum[x]);
            seg::updatepos(l, r, x);
        }
    }
  
    return 0;
}