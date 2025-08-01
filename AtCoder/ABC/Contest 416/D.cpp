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
    map<int,int> mp;
    vi a(n), b(n);
    for (auto &e: a) {
        int bb;
        cin >> bb;
        e = bb%m;
    }
    for (auto &e: b) {
        int bb;
        cin >> bb;
        e = bb%m;
        if (mp.count(e)) mp[e]++;
        else mp[e] = 1;
    }
    sort(a.rbegin(), a.rend());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cmp = m-a[i];
        auto it = mp.lower_bound(cmp);
        if (it == mp.end()) {
            --it;
        }
        auto [f, s] = *it;
        ans += (a[i] + f)%m;
        mp[f]--;
        if (s == 1) mp.erase(f);
    }

    cout << ans << endl;
}

signed main() {
    fastio();
    int t; cin >> t;
    while (t--) {
        solve();
    }
  
    return 0;
}