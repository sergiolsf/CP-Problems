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
    cout.tie(NULL);
}

void solve() {
    int n;
    cin >> n;
    vi v;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (!st.count(a)) {
            st.insert(a);
            v.push_back(a);
        }        
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    for (int i = 1; i <= n; i++) {
        if (!st.count(i)) {
            cout << i << " ";
        }
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