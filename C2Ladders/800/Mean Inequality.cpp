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
    vi a(2*n);
    for (auto &i: a) cin >> i;
    sort(all(a));

    for (int i = 1; i <= 2*n; i++) {
        if (i&1) {
            cout << a[i/2];
        } else {
            cout << a[n+(i-1)/2];
        }
        cout << (i == 2*n ? "\n" : " ");
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