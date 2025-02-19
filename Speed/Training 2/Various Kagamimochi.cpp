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
    int n;
    cin >> n;
    int ans = 0;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int l = -1; // < 2*a[i]
        int r = n; // >= 2*a[i]
        while (r-l!=1) {
            int m = (r+l)/2;
            if (a[m] < 2*a[i]) l = m;
            else r = m;
        }
        ans += (n-r);
    }
    cout << ans << endl;
  
    return 0;
}