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
    int n, x; cin >> n >> x;
    vi a(n);
    for (auto &i: a) cin >> i;
    sort(all(a));

    int ans = 0;
    int sum = 0;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] >= x) {
            ans++;
        } else {
            sum++;
            if (sum*a[i] >= x) {
                ans++;
                sum = 0;
            }
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