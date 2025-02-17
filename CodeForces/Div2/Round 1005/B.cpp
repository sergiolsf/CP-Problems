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
    int n;
    cin >> n;
    vi a(n+1);
    vector<bool> umaVez(n+1, false);
    vector<bool> maisVezes(n+1, false);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (umaVez[a[i]]) maisVezes[a[i]] = true;
        umaVez[a[i]] = true;
    }

    int l = 1, r = 0;
    int L = 1, R = 0;

    for (int i = 1; i <= n; i++) {
        if (!maisVezes[a[i]]) r = i;
        else l = i+1;
        if (r-l >= R-L) {
            L = l;
            R = r;
        }
    }

    if (R == 0) cout << 0 << endl;
    else cout << L << " " << R << endl;
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