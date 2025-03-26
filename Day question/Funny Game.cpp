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
    vi v(n+1);
    vector<pii> ans;
    map<int,int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[i] = v[i];
    }
    for (int i = n-1; i >= 1; i--) {
        map<int,int> aux;
        for(auto e: mp) {
            int u = e.first, v = e.second;
            if (aux.count(v%i)) {
                ans.push_back({aux[v%i], u});
                mp.erase(u);
                break;
            }
            aux[v%i] = u;
        }
    }
    cout << "YES\n";
    for (int i = n-2; i >= 0; i--) {
        cout << ans[i].first << " " << ans[i].second << endl;
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