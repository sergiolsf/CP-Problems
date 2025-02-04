#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(all(a));
    sort(all(b));

    int ult = -1;
    int conta = 0, contb = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != ult) {
            conta++;
            ult = a[i];
        }
    }
    ult = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] != ult) {
            contb++;
            ult = b[i];
        }
    }

    if ((conta < 3 && contb == 1) || (contb < 3 && conta == 1)) {
        cout << "NO\n";
    } else cout << "YES\n";
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