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
    int s = 8;
    int z = 3, u = 1, d = 2, c = 1, t = 1;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (s == 0) continue;

        if (a == 0) {
            z--;
            if (z >= 0) s--;
        } else if (a == 1) {
            u--;
            if (u >= 0) s--;
        } else if (a == 2) {
            d--;
            if (d >= 0) s--;
        } else if (a == 3) {
            t--;
            if (t >= 0) s--;
        } else if (a == 5) {
            c--;
            if (c >= 0) s--;
        }

        if (s == 0) {
            cout << i+1 << endl;
        }
    }

    if (s != 0) cout << 0 << endl;
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