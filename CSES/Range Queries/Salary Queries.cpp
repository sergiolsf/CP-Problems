#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

#define int long long
typedef pair<int,int> pii;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ost;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

signed main() {
    fastio();
    ost st;
    int n, q; cin >> n >> q;
    vi sal(n+1);

    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        st.insert({p, i});
        sal[i] = p;
    }

    while (q--) {
        char op; cin >> op;
        int a, b; cin >> a >> b;
        if (op == '!') {
            st.erase({sal[a], a});
            st.insert({b, a});
            sal[a] = b;
        } else {
            int ans = st.order_of_key({b+1, 0}) - st.order_of_key({a, 0});
            cout << ans << endl;
        }
    }
    
  
    return 0;
}