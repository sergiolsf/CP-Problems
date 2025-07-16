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

signed main() {
    fastio();
    int n, k; cin >> n >> k;
    vi l(n), r(n);
    for (auto &e: l) cin >> e;
    for (auto &e: r) cin >> e;

    sort(all(l));
    sort(all(r));


    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] + r[i] <= k) {
            ans++;
            k -= (l[i]+r[i]);
        } else break;
    }

    cout << ans << endl;
  
    return 0;
}