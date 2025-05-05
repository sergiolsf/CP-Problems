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
    int n, k; cin >> n >> k;
    vi a(n), b(n);
    int fixo = -1;
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != -1) fixo = a[i]+b[i];
    }

    if (fixo != -1) {
        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                if (a[i]+b[i] != fixo) {
                    cout << "0\n";
                    return;
                }
            } else {
                if (fixo-a[i] < 0 || fixo-a[i] > k) {
                    cout << "0\n";
                    return;
                }
            }
        }
        cout << "1\n";
    } else {
        int l = 0, r = 2*k;
        for (int i = 0; i < n; i++) {
            r = min(r, a[i]+k);
            l = max(l, a[i]);
        }
        if (r < l) {
            cout << "0\n";
            return;
        } else {
            cout << r-l+1 << endl;
            return;
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