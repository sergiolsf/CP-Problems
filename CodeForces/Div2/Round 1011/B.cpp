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
    int n; cin >> n;
    vi a(n);
    vector<pii> ans;
    int c = 0;
    for (auto &i: a) cin >> i;
    if (a[0] == 0 || a[1] == 0) {
        ans.pb({1,2});
        c++;
    }
    bool flag = false;
    for (int i = 2; i < n; i++) {
        if (a[i] == 0) {
            flag = true;
            break;
        }
    }
    if (flag) {
        ans.pb({3-c, n-c});
        ans.pb({1,3-c});
    } else {
        ans.pb({1, n-c});
    }
    cout << ans.size() << endl;
    for (auto e: ans) {
        cout << e.first << " " << e.second << endl;
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