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
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> vs;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        vs.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        int sz = vs[i].size();
        if (sz <= m) {
            m -= sz;
            ans++;
        } else break;
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