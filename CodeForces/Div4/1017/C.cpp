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
    vector<bool> vb (2*n+1, false);
    vector<int> v(2*n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a; cin >> a;
            v[i+j] = a;
            vb[a] = true;
        }
    }
    for (int i = 1; i <= 2*n; i++) {
        if (!vb[i]) {
            v[1] = i;
            break;
        }
    }
    
    for (int i = 1; i <= 2*n; i++) {
        cout << v[i] << (i == 2*n ? "\n" : " ");
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