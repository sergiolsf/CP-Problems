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

vi divisores(int a) {
    vi ans;
    for (int i = 1; i*i <= a; i++) {
        if (a%i == 0) {
            ans.push_back(i);
            if (i*i != a) ans.push_back(a/i);
        }
    }
    return ans;
}

void solve() {
    int n, q; cin >> n >> q;
    map<int, vi> mp;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        mp[a].push_back(i);
    }

    while (q--) {
        int k, l, r; cin >> k >> l >> r;
        vi div = divisores(k);
        vector<pii> vp;

        for (auto e: div) {
            if (mp.count(e)) {
                auto pt = lower_bound(all(mp[e]), l);
                if (pt == mp[e].end()) continue;
                int lb = *pt;
                if (lb <= r) vp.push_back({lb, e});
            }
        }
        sort(all(vp));
        int ans = 0;
        for (auto e: vp) {
            if (k%e.second == 0) {
                ans += (e.first-l)*k;
                while (k%e.second == 0) k /= e.second;
                l = e.first;
            }
        }
        
        ans += (r-l+1)*k;
        cout << ans << endl;
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