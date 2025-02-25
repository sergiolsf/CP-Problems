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
    int k, n, m;
    cin >> k >> n >> m;
    vi a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vi ans;

    int i = 0, j = 0;
    while (i < n || j < m) {
        if (i < n) {
            if (a[i] == 0) {
                k++;
                i++;
                ans.pb(0);
                continue;
            } else if (a[i] <= k) {
                ans.pb(a[i]);
                i++;
                continue;
            }
        }
        if (j < m) {
            if (b[j] == 0) {
                k++;
                j++;
                ans.pb(0);
                continue;
            } else if (b[j] <= k) {
                ans.pb(b[j]);
                j++;
                continue;
            }
        }
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ((i == ans.size()-1) ? "\n" : " ");
    }
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