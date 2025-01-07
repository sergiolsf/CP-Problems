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
    cout.tie(NULL);
}

void solve() {
    int m, a, b,c, m1, m2, ans = 0;
    cin >> m >> a >> b >> c;
    m1 = m2 = m;

    if (m1 >= a) {
        m1 -= a;
        ans += a;
    } else {
        ans += m1;
        m1 = 0;
    }

    if (m2 >= b) {
        m2 -= b;
        ans += b;
    } else {
        ans += m2;
        m2 = 0;
    }

    if (m1 + m2 > 0) {
        if (c <= m1 + m2) ans += c;
        else ans += m1 + m2;
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