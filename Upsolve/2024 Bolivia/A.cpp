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

int a, b, c, l, r; 

int calcula(int x1, int x2) {
    int s1 = 2*a*(x1*x1*x1)+3*b*(x1*x1)+6*c*x1;
    int s2 = 2*a*(x2*x2*x2)+3*b*(x2*x2)+6*c*x2;
    return abs(s2-s1);
}

void solve() {
    cin >> a >> b >> c >> l >> r;
    int x1, x2;
    int delta = b*b - 4*a*c;
    if (delta < 0 || ((int) sqrt(delta))*((int) sqrt(delta)) != delta) {
        x1 = l, x2 = r;
    } else {
        x1 = (-b - (int)(sqrt(delta)));
        x2 = (-b + (int)(sqrt(delta)));
        if (x1%(2*a) || x2%(2*a)) {
            x1 = l, x2 = r;
        }
        x1 /= 2*a;
        x2 /= 2*a;
    }

    int ans = 0;

    if (x1 >= l && x1 <= r) {
        if (x2 >= l && x2 <= r) {
            ans += calcula(l, x1);
            ans += calcula(x1, x2);
            ans += calcula(x2, r);
        } else {
            ans += calcula(l, x1);
            ans += calcula(x1, r);
        }
    } else if (x2 >= l && x2 <= r) {
        ans += calcula(l, x2);
        ans += calcula(x2, r);
    } else {
        ans += calcula(l, r);
    }

    int div = __gcd(6LL, ans);
    cout << ans/div << "/" << 6/div << endl;

}

signed main() {
    fastio();
    int t; cin >> t;
    while (t--) {
        solve();
    }
  
    return 0;
}