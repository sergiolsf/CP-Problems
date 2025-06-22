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
    int n, s; cin >> n >> s;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int dx, dy, x, y; cin >> dx >> dy >> x >> y;
        if (dx == 1) {
            int sx = s-x;
            if (y+sx*dy == 0 || y+sx*dy == s) ans++;
        } else {
            int sx = x;
            if (y+sx*dy == 0 || y+sx*dy == s) ans++;
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