#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ost;


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

const int MAXN = 10'000'001;
vector<bool> marc(MAXN, false);
ost tr;

void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a = (n/i);
        int u = tr.order_of_key(a);
        if (*tr.find_by_order(u) != a) u--;
        ans += u+1;
    }
    cout << ans << endl;
}

signed main() {
    fastio();

    for (int i = 2; i < MAXN; i++) {
        if (!marc[i]) {
            tr.insert(i);
        } else continue;
        for (int j = i*i; j < MAXN; j+=i) {
            marc[j] = true;
        }
    }

    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}