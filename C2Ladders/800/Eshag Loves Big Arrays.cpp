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
    vi a(n);
    for (auto &i: a) cin >> i;
    sort(all(a));
    int ans = 0;
    int sum = 0; int cont = 0;
    for (auto i: a) {
        sum += i; cont++;
        if (i > sum/cont) {
            ans++;
            sum -= i;
            cont--;
        }
    }
    cout << ans << endl;
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