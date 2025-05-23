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
    int n; cin >> n;
    vector<pii> v(n);
    for (auto &[a, d]: v) cin >> a >> d;

    sort(all(v));

    int t = 0, ans = 0;
    for (auto &[a, d]: v) {
        t += a;
        ans += d-t;
    }

    cout << ans << endl;
  
    return 0;
}