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

int func(int x, int xi, int ri) {
    int y = sqrtl(ri*ri - (x-xi)*(x-xi));
    return y;
}

void solve() {
    int n, m; cin >> n >> m;
    vi X(n), R(n);
    for (auto &i: X) cin >> i;
    for (auto &i: R) cin >> i;

    map<int, pii> mp;
    for (int i = 0; i < n; i++) {
        int x = X[i], r = R[i];
        for (int j = x-r; j <= x+r; j++) {
            int y = func(j, x, r);
            if (mp.count(j)) {
                pii Y = mp[j];
                mp[j] = {min(-y, Y.first), max(y, Y.second)};
            } else {
                pii p = {-y, y};
                mp[j] = p;
            }
        }
    }

    int ans = 0;

    for (auto e: mp) {
        int y1 = e.second.first, y2 = e.second.second;
        ans += (y2-y1+1);
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