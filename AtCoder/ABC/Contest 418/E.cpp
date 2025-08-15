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

int val (int a, int b) {
    return ((a << 32LL) | b);
}

signed main() {
    fastio();
    int n; cin >> n;
    vi x(n+1), y(n+1);
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    unordered_map<int, int> ang;
    unordered_map<int, int> ret;

    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            int dx = x[i]-x[j];
            int dy = y[i]-y[j];

            int g = __gcd(dx, dy);
            dx /= g; dy /= g;

            if (dy < 0) {
                dy = -dy;
                dx = -dx;
            }

            ang[val(dx, dy)]++;
            
            int mx = x[i]+x[j];
            int my = y[i]+y[j];
            ret[val(mx, my)]++;
        }
    }

    int ans = 0;
    for (auto [p, e]: ang) ans += e*(e-1)/2;
    for (auto [p, e]: ret) ans -= e*(e-1)/2;

    cout << ans << endl;  
    return 0;
}