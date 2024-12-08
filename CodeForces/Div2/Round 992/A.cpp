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
    int n, k;
    cin >> n >> k;
    vector<int> v (n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                if (abs(v[i]-v[j])%k == 0) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << "YES\n" << i << endl;
            return;
        }
    }

    cout << "NO\n";
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