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
    int n, m; cin >> n >> m;
    vi a(m);
    for (auto &i: a) cin >> i;
    sort(all(a));

    int ans = 0;
    for (int k = 1; k < n; k++) {
        if (lower_bound(all(a), k) == a.end()) continue;
        if (lower_bound(all(a), n-k) == a.end()) continue;
        int x = lower_bound(all(a), k)-a.begin();
        int y = lower_bound(all(a), n-k)-a.begin();
        x = m-x; y = m-y;
        ans += x*y-min(x,y);
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