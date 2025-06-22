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
    int k, a, b, x, y; cin >> k >> a >> b >> x >> y;
    if (y < x || (y == x && b < a)) {
        swap(x,y);
        swap(a,b);
    }
    int ans = 0;
    if (k - a >= 0) {
        ans += (k-a)/x;
        k -= x*ans;
        if (k >= a) {
            ans++;
            k -= x;
        }
    }
    if (k - b >= 0) {
        int A = (k-b)/y;
        ans += A;
        k -= y*A;
        if (k >= b) {
            ans++;
            k -= y;
        }
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