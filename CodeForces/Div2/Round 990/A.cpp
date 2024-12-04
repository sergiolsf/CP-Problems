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

bool v[10000];

void solve() {
    int n, ans = 0, tot = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tot += x;
        if (v[tot]) ans++;
    }

    cout << ans << endl;
}

signed main() {
    fastio();

    for (int i = 1; i <= 100; i += 2) {
        v[i*i] = true;
    }

    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}