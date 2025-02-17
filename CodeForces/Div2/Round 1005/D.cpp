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
    int n, q;
    cin >> n >> q;
    vi a(n+1);
    int ult = 0;
    vi b;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        b.pb(a[i]^ult);
        ult = a[i]^ult;
    }
    
    for (auto e: b) cout << e << " ";
    cout << endl;

    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
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