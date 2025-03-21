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
    for(auto &i : a) cin >> i;

    sort(all(a));

    vi c(n+1, 0);
    int p = m-1;

    for(int j = n; j > 0; j--) {
        while (p >= 0 && a[p] >= j) p--;
        c[j] = m-(p+1);
    }

    int ans = 0;
    for(int j=1; j < n; j++){
        int x = c[j], y = c[n-j], z = c[max(j,(n-j))];
        ans += x*y - z;
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
