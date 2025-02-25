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
    int n, x;
    cin >> n >> x;
    if (n == 1) cout << x << endl;
    else {
        int i;
        int p = 0;
        cout << 0 << " ";
        for (i = 1; i < min(n-1, x); i++) {
            if (i&x) { 
                cout << i << " ";
                p |= i;
            }
            else break;
        }
        
        for (; i < n; i++) {
            if ((p|i) == x && i <= x) {
                cout << i << (i == n-1 ? "\n" : " ");
            }
            else cout << x << (i == n-1 ? "\n" : " ");
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