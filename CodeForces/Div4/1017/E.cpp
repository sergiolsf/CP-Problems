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

const int MAX_N = 31;

void solve() {
    int n; cin >> n;
    vi a(n+1);
    vi cnt(MAX_N, 0);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        for (int j = 0; j < MAX_N; j++) {
            if (a[i]&(1LL << j)) cnt[j]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int d = sum+n*a[i];
        for (int j = 0; j < MAX_N; j++) {
            if (a[i]&(1LL << j)) {
                d -= 2*cnt[j]*(1LL << j);
            }
        }
        ans = max(ans, d);
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