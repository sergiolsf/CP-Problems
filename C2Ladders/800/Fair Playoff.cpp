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
    int n = 4;
    vi a(n);
    vi v(n);

    for (int i = 0; i < 4; i ++) {
        cin >> v[i];
        a[i] = v[i];
    }
    sort(all(v));

    vi b(2);
    b[0] = max(a[0], a[1]);
    b[1] = max(a[2], a[3]);

    sort(all(b));

    if (b[0] == v[2] && b[1] == v[3]) {
        cout << "YES\n"; 
    } else cout << "NO\n";
    
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