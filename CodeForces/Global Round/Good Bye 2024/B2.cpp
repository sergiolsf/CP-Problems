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

void solve() {
    int n;
    cin >> n;
    vi a(2*n+1, 0);
    vi sum(2*n+1, 0);
    vector<pii> v(n+1);

    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        v[i] = {l,r};
        if (l == r) {
            a[l]++;
        }
    }

    for (int i = 1; i <= 2*n; i++) {
        sum[i] = sum[i-1];
        if (a[i]) sum[i]++;
    }

    for (int i = 1; i <= n; i++) {
        int l = v[i].first, r =  v[i].second;
        int range = sum[r] - sum[l-1];

        if (l == r && a[l] > 1) cout << 0;
        else if (l != r && range == r-l+1) cout << 0;
        else cout << 1;
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