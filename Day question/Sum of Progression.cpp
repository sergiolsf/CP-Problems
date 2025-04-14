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

const int d0 = 448;
const int MAX_N = 100'005;

vvi sum(d0, vi(MAX_N));
vvi sumMult(d0, vi(MAX_N));
vi a(MAX_N);
int n, q; 

void func() {
    for (int d = 1; d < min(d0, n+1); d++) {
        for (int i = 1; i <= n; i++) {
            int k = (i%d == 0 ? 0 : 1);
            k += i/d;
            int m = max(0LL, i-d);
            sum[d][i] = sum[d][m] + a[i];
            sumMult[d][i] = sumMult[d][m] + k*a[i];
        }
    }
}

void solve() {
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) cin >> a[i];

    func();

    while (q--) {
        int s, d, k; cin >> s >> d >> k;
        int ans = 0;
        if (d >= d0) {
            for (int i = 1; i <= k; i++) {
                ans += a[s+(i-1)*d]*i;
            }
        } else {
            int m = max(0LL, s-d);
            int x = (s%d == 0 ? 0 : 1);
            x += s/d;
            ans = (sumMult[d][s+(k-1)*d] - sumMult[d][m]) - (x-1)*(sum[d][s+(k-1)*d] - sum[d][m]);
        }
       cout << ans << " ";
    }
    cout << endl;
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