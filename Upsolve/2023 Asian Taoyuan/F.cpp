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

struct pos {
    int d, s, i;
    bool operator < (pos other) const {
        if (s*other.d != d*other.s) return s*other.d > d*other.s;
        return i < other.i;
    }
};

void solve() {
    int n; cin >> n;
    vector<pos> v(n);
    for (int i = 0; i < n; i++) {
        v[i].i = i+1;
        cin >> v[i].d >> v[i].s;
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        cout << v[i].i << (i == n-1 ? "\n" : " ");
    }
}

signed main() {
    fastio();
    int t; cin >> t;
    while (t--) {
        solve();
    }
  
    return 0;
}