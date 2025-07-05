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

const int INF = 1'000'000'000'000'000'000;

void solve() {
    int n; cin >> n;
    vi a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (i > 1 && i < n) {
            if (a[i-1] <= a[i] && a[i] >= a[i+1]) flag = true;
            if (a[i-1] >= a[i] && a[i] <= a[i+1]) flag = true;
        } 
        if (i > 1 && abs(a[i]-a[i-1]) <= 1) {
            cout << 0 << endl;
            return;
        }
    }

    if (flag) cout << 1 << endl;
    else cout << -1 << endl;
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