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
    map<int,int> X;
    map<int,int> diag;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (X.count(x)) X[x]++;
        else X[x] = 1;
        if (diag.count(x+y)) diag[x+y]++;
        else diag[x+y] = 1;
    }

    int xAns, dAns;
    for (auto e: X) {
        if (e.second&1) {
            xAns = e.first;
            break;
        }
    }
    for (auto e: diag) {
        if (e.second&1) {
            dAns = e.first;
        }
    }

    cout << xAns << " " << dAns-xAns << endl;


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