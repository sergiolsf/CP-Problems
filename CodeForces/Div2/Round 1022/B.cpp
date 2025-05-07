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

const int MAX_N = 50;

void solve() {
    int n, x; cin >> n >> x;

    int cont = 0;
    for (int i = 0; i < MAX_N; i++) {
        if ((1LL<<i)&x) cont++;
    }

    if (n <= cont) {
        cout << x << endl;
        return;
    }

    int d = n-cont;
    if (d%2 == 0) {
        cout << x+d << endl;
        return;
    }

    if (x == 0) {
        if (n == 1) {
            cout << -1 << endl;
            return;
        } else cout << n+3 << endl;
        //if (n&1) cout << n+3 << endl;
        //else cout << n << endl;
    } else if (x == 1) {
        cout << n+3 << endl;
    } else {
        cout << x+d+1 << endl;
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