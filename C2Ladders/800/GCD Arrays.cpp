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
    int l, r, k; cin >> l >> r >> k;
    if (l == r) {
        if (l == 1) cout << "NO\n";
        else cout << "YES\n";
        return;
    }
    int moves = (r-l+1)-(r/2 - (l-1)/2);
    if (moves <= k) cout << "YES\n";
    else cout << "NO\n";
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