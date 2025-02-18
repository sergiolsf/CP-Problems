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

const int INF = 1e18;
const int NINF = -INF;

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = NINF;

    for (int i = max(n-2*k-1, 1LL); i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            ans = max(ans, i*j - k * (a[i]|a[j]));
        }
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