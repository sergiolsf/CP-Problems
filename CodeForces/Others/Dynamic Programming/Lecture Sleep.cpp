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

signed main() {
    fastio();
    int n, k; cin >> n >> k;
    vi a(n+1);
    vi t(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> t[i];

    vi prev(n+1, 0);
    vi prevSleep(n+1, 0);
    for (int i = 1; i <= n; i++) {
        prev[i] = prev[i-1] + a[i];
        prevSleep[i] = prevSleep[i-1] + a[i]*t[i];
    }

    int ans = 0;
    for (int i = 1; i <= n-k+1; i++) {
        int p = prevSleep[i-1] + (prev[i+k-1]-prev[i-1]) + (prevSleep[n]-prevSleep[i+k-1]);
        ans = max(ans, p);
    }

    cout << ans << endl;
  
    return 0;
}