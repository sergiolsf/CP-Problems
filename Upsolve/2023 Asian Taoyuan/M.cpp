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
    vi task(n+1), val(n+1);
    for (int i = 1; i <= n; i++) cin >> task[i];
    for (int i = 1; i <= n; i++) cin >> val[i];

    vector<pair<pii, int>> v;
    for (int i = 1; i <= n; i++) {
        v.push_back({{val[i], i}, task[i]});
    }
    sort(all(v));
    for(int i = 0; i < n; i++) {
        cout << v[i].second << (i == n-1 ? "\n" : " ");
    }
}

signed main() {
    fastio();
    int t; cin >> t;
    while(t--) {
        solve();
    }
  
    return 0;
}