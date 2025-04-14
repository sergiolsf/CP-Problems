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
    int n, k, x; cin >> n >> k >> x;
    vi a(n+1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (k*sum < x) {
        cout << 0 << endl;
        return;
    }

    int m = x/sum;
    int ind = n*m;
    int s = m*sum;
    for (int i = n; i > 0; i--) {
        if (s+a[i] < x) {
            ind++;
            s += a[i];
        } else break;
    }

    if (s == x) ind--;

    int ans = (k*n)-ind;

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