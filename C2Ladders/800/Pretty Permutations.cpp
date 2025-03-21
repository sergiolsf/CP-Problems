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
    if (n%2 == 0) {
        for (int i = 1; i <= n/2; i++) {
            cout << 2*i << " " << 2*i-1 << (i == n/2 ? "\n" : " ");
        }
    } else {
        int k = n-3;
        for (int i = 1; i <= k/2; i++) {
            cout << 2*i << " " << 2*i-1 << " ";
        }
        cout << n << " " << n-2 << " " << n-1 << endl;
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