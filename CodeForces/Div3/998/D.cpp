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

    for (int i = 1; i < n; i++) {
        if (a[i-1] == 0 && a[i] != 0) {
            if (i == n-1) {
                cout << "YES" << endl;
                return;
            } else {
                continue;
            }
        }
        if (a[i-1] > a[i]) {
            cout << "NO" << endl;
            return;
        }
        a[i] -= a[i-1];
        a[i-1] = 0;
    }

    for (int i = 0; i < n-1; i++) {
        if (a[i] != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

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