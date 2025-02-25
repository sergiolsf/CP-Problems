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

int maior (int k) {
    int n = (1+sqrt(1+8*k))/2;
    int p = n-2;
    if ((n-1)*(n-2)/2 <= k) p = n-1;
    if (n*(n-1)/2 <= k) p = n;
    if ((n+1)*(n)/2 <= k) p = n+1;
    if ((n+2)*(n+1)/2 <= k) p = n+2;
    return p;
}

void solve() {
    int k;
    cin >> k;
    int y = -1e9, x = -1e9;
    vector<pii> ans;

    while (k >= 1) {
        int n = maior(k);
        k -= n*(n-1)/2;
        for (int i = 1; i <= n; i++) {
            ans.pb({x,y});
            x++;
        }
        y++;
        x--;
        if (k >= 1) {
            //ans.pb({x, y});
            //x++;
            if (k == 1) ans.pb({x, y});
            k--;
        }
    }
    //if (k == 1) ans.pb({x-1, y});
    cout << ans.size() << endl;
    if (ans.size()) {
        for (auto e: ans) {
            cout << e.first << " " << e.second << endl;
        }
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