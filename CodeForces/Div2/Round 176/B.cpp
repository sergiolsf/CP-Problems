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
    int n, k; cin >> n >> k;
    vi a(n);
    for (auto &i: a) cin >> i;

    int ans = 0;

    if (k == 1) {
        for (int i = 1; i < n-1; i++) {
            ans = max({ans, a[i]+a[0], a[i]+a[n-1]});
        }
        ans = max(ans, a[0]+a[n-1]);
        cout << ans << endl;
        return;
    }


    sort(all(a));

    for (int i = n-1; i > (n-1-(k+1)); i--) {
        ans += a[i];
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