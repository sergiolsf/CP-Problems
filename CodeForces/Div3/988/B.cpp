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
    int k;
    cin >> k;
    set<int> st;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    for (int i = 1; i*i <= (k-2); i++) {
        if (st.count(i) && (k-2)%i == 0) {
            if (st.count((k-2)/i)) {
                cout << i << " " << (k-2)/i << endl;
                return;
            }
        }
    }
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