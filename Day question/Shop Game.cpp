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
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    vi ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
      return b[i] > b[j];
    });
    int f = 0, p = 0;
    for (int i : ord) p += max(0LL, b[i] - a[i]);
    int ans = 0;
    multiset<int> s;
    if (s.size() == k) ans = max(ans, p - f);
    for (int i : ord) {
      p -= max(0LL, b[i] - a[i]);
      s.insert(a[i]);
      f += a[i];
      if (s.size() > k) {
        f -= *s.rbegin();
        s.erase(--s.end());
      }
      if (s.size() == k) ans = max(ans, p - f);
    }
    cout << ans << '\n';
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