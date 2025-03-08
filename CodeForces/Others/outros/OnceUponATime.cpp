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

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int lcm(int a, int b) {
    return a/__gcd(a,b) * b;
}

signed main() {
    fastio();
    int n, m, a, k; cin >> n >> m >> a >> k;
    while (n && m && a && k) {
        int g = __gcd(m,a);
        int cte = k+a-n;
        if (cte%g != 0) {
            cout << "Impossible" << endl; 
        } else {
            int lambda = cte/g;
            int X, Y;
            gcdModified(m, a, X, Y);
            int x = lambda*X, y = -lambda*Y;
            int ans = n+m*x;

            if (x < 0 || y < 0) {
                int shift = lcm(m,a)/g;
                int l = 0;
                ans = -1;
                int ans1 = 0;
                int ans2 = 0;
                if (x < 0) {
                    l = -x/shift + (-x % shift != 0);
                    if (x+l*shift >= 0 && y+l*shift >= 0) {
                        ans1 = n+m*(x+l*shift);
                        ans = ans1;
                    }
                } else if (y < 0) {
                    l = -y/shift + (-y % shift != 0);
                    if (y+l*shift >= 0 && x+l*shift >= 0) {
                        ans2 = n+m*(x+l*shift);
                        ans = ans2;
                    }
                }
                if (ans1 && ans2) ans = min (ans1, ans2);

            }

            //cout << x << " " << y << " " << n+m*x << " " << k+a+a*y << endl;
            if (ans == -1) cout << "Impossible" << endl;
            else cout << ans << endl;
        }
        cin >> n >> m >> a >> k;
    }
  
    return 0;
}