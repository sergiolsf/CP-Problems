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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vi val(n+1, 0);
    for (int i = 0; i < n; i++) {
        val[i+1] = val[i] + (int) (s[i]-'a'+1);
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << val[r] - val[l-1] << endl;
    }
}

signed main() {
    fastio();
    int t = 1;
    while(t--) {
        solve();
    }    
    return 0;
}