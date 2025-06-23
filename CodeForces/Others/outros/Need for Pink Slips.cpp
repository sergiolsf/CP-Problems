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

const double EPS = 1e-9;

double v;

double bruteForce(double c, double m, double p, int quant) {
    if (c <= EPS && m <= EPS) return quant;

    double ans = quant*p;
    if (c > EPS) {
        double x = min(c, v);
        if (m > EPS) ans += c*bruteForce(c-x, m+x/2.0, p+x/2.0, quant+1);
        else ans += c*bruteForce(c-x, 0.0, p+x, quant+1);
    }
    if (m > EPS) {
        double x = min(m, v);
        if (c > EPS) ans += m*bruteForce(c+x/2.0, m-x, p+x/2.0, quant+1);
        else ans += m*bruteForce(0.0, m-x, p+x, quant+1);
    }

    return ans;
}

void solve() {
    double c, m, p; cin >> c >> m >> p >> v;
    double ans = bruteForce(c, m, p, 1);
    cout << fixed << setprecision(20) << ans << endl;
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