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
    int n; cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;

    for (int i = 0; i < n; i++) {
        int g = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                g = __gcd(g, a[j]);
            }
        }
        if (g != a[i]) {
            cout << "Yes\n";
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    cout << 1;
                } else cout << 2;
                cout << (j == n-1 ? "\n" : " ");
            }
            return;
        }
    }

    cout << "No\n";
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