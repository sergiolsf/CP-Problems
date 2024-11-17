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

int t, n;

void solve() {
    cin >> n;
    set<int> st;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (st.count(x)) {
            ans++;
            st.erase(x);
        }
        else {
            st.insert(x);
        }
    }
    cout << ans << endl;
}

signed main() {
    fastio();
    cin >> t;
    while (t--) {
        solve();
    }    
    return 0;
}