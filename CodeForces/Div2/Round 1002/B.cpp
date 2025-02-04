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
    int n, k;
    cin >> n >> k;
    vi a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == k) {
        for (int i = 1; i <= n/2; i++) {
            if (a[2*i] != i) {
                cout << i << endl;
                return;
            }
        }
        cout << n/2 + 1 << endl;
    } else {
        int cont = n-1;
        int i = 2;
        while (cont >= k-1) {
            if (a[i] != 1) {
                cout << 1 << endl;
                return;
            }
            i++;
            cont--;
        }
        cout << 2 << endl;
        return;
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