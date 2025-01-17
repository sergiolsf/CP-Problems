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
    int n;
    cin >> n;
    vi a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n==1) cout << 1 << endl;
    else if (n%2 == 0) {
        int maxDif = 0;
        for (int i = 1; i < n; i+=2) {
            maxDif = max(maxDif, a[i]-a[i-1]);
        }
        cout << maxDif << endl;
    } else { 
        int ans = 1e18+1;
        for (int i = 0; i < n; i+=2) {
            int maxDif = 0;
            for (int j = 0; j < n; j += 2) {
                if (j == i) {
                    j++;
                }
                if (j >= n) continue;
                maxDif = max(maxDif, a[j+1]-a[j]);
            }
            ans = min(ans, maxDif);
        }
        cout << ans << endl;
    }
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