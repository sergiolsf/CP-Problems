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
}

void solve() {
    int n; 
    cin >> n;
    vector<pii> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i].second;
    }

    int ans = -1e17;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (j != i) sum += max(v[j].first, v[j].second);
            else sum += v[j].first + v[j].second;
        }
        ans = max(ans, sum);
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