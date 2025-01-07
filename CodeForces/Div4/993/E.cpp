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
    int k, lx, rx, ly, ry, ans = 0;
    cin >> k >> lx >> rx >> ly >> ry;

    int maiorExp = 1;
    int Exp = 1;

    while (Exp <= ry) {
        maiorExp = Exp;
        Exp *= k;
    }

    for (int i = 1; i <= maiorExp; i *= k) {
        int l = ly/i, r = ry/i;
        l = max(l, lx);
        r = min(r, rx);

        if (r >= l) {
            ans += r-l+1;
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