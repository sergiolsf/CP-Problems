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
}

void solve() {
    int n;
    cin >> n;
    vector<pii> col (n+1);

    for (int i = 1; i <= n; i++) {
        cin >> col[i].first;
    }

    for (int i = 1; i <= n; i++) {
        cin >> col[i].second;
    }

    int sum = 0;
    int maxMin = -1e10;
    for (int i = 1; i <= n; i++) {
        sum += max(col[i].first, col[i].second);
        maxMin = max(maxMin, min(col[i].first, col[i].second));
    }

    cout << sum + maxMin << endl;

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