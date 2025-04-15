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
    int n, k; cin >> n >> k;
    vector<pii> vp (n);
    for (int i = 0; i < n; i++) cin >> vp[i].first;
    for (int i = 0; i < n; i++) cin >> vp[i].second;

    sort(all(vp));

    for (int i = 0; i < n; i++) {
        if (vp[i].first <= k) k += vp[i].second;
        else break;
    }

    cout << k << endl;
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