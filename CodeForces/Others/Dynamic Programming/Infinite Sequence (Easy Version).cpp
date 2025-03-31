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

const int MAXN = 1'000'000;

int n, r, l, p;
vi v(MAXN);

int dp(int m) {
    if (m <= (2*n+1)) return v[m];
    if ((m/2)%2 == 1) return p;
    return p^dp(m/2 - 1);
}

void solve() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) cin >> v[i];
    int k = 0;
    if (n%2 == 0) {
        for (int i = 1; i <= n/2; i++) k ^= v[i];
        n++;
        v[n] = k;
    }

    ///
    k = 0;
    for (int i = 1; i <= n/2; i++) {
        k ^= v[i];
    }
    int j = n+1;
    int y = (n/2)+1;
    while (j <= 2*n+1) {
        k ^= v[y];
        v[j] = v[j+1] = k;
        j += 2;
        y++;
    }
    ///

    p = 0;
    for (int i = 1; i <= n; i++) p ^= v[i];

    if (l <= (2*n+1)) cout << v[l] << endl;
    else if ((l/2)%2 == 1) cout << p << endl;
    else cout << (p^dp((l/2) - 1)) << endl;    
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