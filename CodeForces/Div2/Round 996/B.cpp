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
    vi a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int delta = -1;
    int minimum = 1e10;

    for (int i = 1; i <= n; i++) {
        if (b[i] > a[i]) {
            if (delta == -1) delta = b[i] - a[i];
            else {
                cout << "NO\n"; 
                return;
            }
        }
        else {
            minimum = min(minimum, a[i]-b[i]);
        }
    }

    if (minimum >= delta) cout << "YES\n";
    else cout << "NO\n";
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