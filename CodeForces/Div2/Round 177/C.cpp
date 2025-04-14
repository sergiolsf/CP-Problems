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
    vi p(n+1), v(n+1), pos(n+1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    set<int> st;
    for (int i = 1; i <= n; i++) {
        int d; cin >> d;
        int u = d;
        //u = p[u];
        //ans++;
        while (!st.count(u)) {
            ans++;
            st.insert(u);
            u = p[u];
        }
        cout << ans << " ";
    }
    cout << endl;
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