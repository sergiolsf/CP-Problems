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
    int n, m, l, r; cin >> n >> m >> l >> r;
    int ansl = 0, ansr = 0;
    for (int i = 0; i < m; i++) {
        if (ansl > l) ansl--;
        else ansr++;
    }
    cout << ansl << " " << ansr << endl;
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