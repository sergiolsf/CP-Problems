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
    int even = 0, odd = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= 2*n; i++) {
        int a;
        cin >> a;
        if (a&1) odd++;
        else even++;
    }
    if (odd == even) cout << "Yes\n";
    else cout << "No\n";
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