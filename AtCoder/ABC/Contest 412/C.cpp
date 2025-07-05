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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int A1 = a[0];
    int An = a[n-1];
    if (An <= 2*A1) {
        cout << 2 << endl;
        return;
    }
    sort(all(a));
    int pos1, posn;
    for (int i = 0; i < n; i++) {
        if (a[i] == A1) {
            pos1 = i;
        }
        if (a[i] == An) {
            posn = i;
            break;
        }
    }

    int cont = 2;
    for (int i = pos1; i <= posn;) {
        if (i == posn) {
            break;
        }

        int j = i+1;
        for (; j <= posn; j++) {
            if (a[j] > 2*a[i]) {
                cont++;
                j--;
                break;
            }
        }
        if (i == j) {
            cout << -1 << endl;
            return;
        }
        i = j;
    }

    cout << cont << endl;
}

signed main() {
    fastio();
    int t; cin >> t;
    while (t--) solve();
  
    return 0;
}