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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi ini(n+1);
    vi sub(n);

    for (int i = 1; i <= n; i++) {
        cin >> ini[i];
    }

    for (int i = 1; i < n; i++) {
        sub[i] = abs(ini[i] - ini[i+1]);
    }

    /// begin the sparse table
    int k = log2(n) + 1;
    vector<vi> st (n, vi(k, 0));


    /// pre-process Sparse Table : nlog(n)
    for (int i = 1; i < n; i++) {
        st[i][0] = sub[i];
    }

    for (int j = 1; j < k; j++) {
        for (int i = 1; i + (1<<j) - 1 < n; i++) {
            st[i][j] = gcd(st[i][j-1], st[i + (1<<(j-1))][j-1]);
        }
    }

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;

        if (l == r) {
            cout << 0 << " ";
        } else {
            /// procurar melhor na sparse table entre l e r-1
            r--;
            int ans;
            int p = log2(r-l+1);
            ans = st[l][p];
            int dif = r - (l + (1<<p) -1 );

            if (dif > 0) {
                ans = gcd(ans, st[l+dif][p]);
            }
            cout << ans << " ";
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