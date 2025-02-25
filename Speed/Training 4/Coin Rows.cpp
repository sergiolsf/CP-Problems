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

const int INF = 1e18;

void solve() {
    int m;
    cin >> m;
    vi lin(m), col(m);
    vi acumLin(m);


    for (int i = 0; i < m; i++) {
        cin >> lin[i];
        if (i >= 1) acumLin[i] = acumLin[i-1] + lin[i];
        else acumLin[i] = lin[i];
    }
    for (int i = 0; i < m; i++) cin >> col[i];

    int ans = INF;
    int c = 0;
    for (int i = 0; i < m; i++) {
        int l = acumLin[m-1] - acumLin[i];
        if (i >= 1) c += col[i-1];
        ans = min(ans, max(l,c));
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