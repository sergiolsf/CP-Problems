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

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));

    int ans = 0;

    for (int i = n-1; i > 0; i--) {
        int le = -1; // - infinito
        int ri = n; // infinito

        while (ri-le != 1) {
            int m = (le+ri)/2;
            if (a[m]+a[i]<=r) le = m;
            else ri = m;
        }

        int lr = -1;
        int rr = n;

        while (rr-lr != 1) {
            int m = (lr+rr)/2;
            if (a[m]+a[i] < l) lr = m;
            else rr = m;
        }

        //cout << le << " " << lr << endl;
        if (le >= i) le = i-1;

        if (le - lr > 0) ans += le - lr;
    }

    cout << ans << endl;
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