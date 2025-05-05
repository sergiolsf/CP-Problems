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
    int n, x; cin >> n >> x;
    if (n == x) {
        for (int i = 0; i < n; i++) {
            cout << i << (i == n-1 ? "\n" : " ");
        }
        return;
    }
    for (int i = 0; i < x; i++) cout << i << " ";
    for (int i = x+1; i < n; i++) cout << i << " ";
    cout << x << endl;
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