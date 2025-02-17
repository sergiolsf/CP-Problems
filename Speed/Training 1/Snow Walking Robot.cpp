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
    string s;
    cin >> s;
    int u = 0, d = 0, l = 0, r = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'U') u++;
        else if (s[i] == 'D') d++;
        else if (s[i] == 'L') l++;
        else r++;
    }
    int p, q;
    p = min(u, d);
    q = min(l, r);

    if (p > 0 && q > 0) {
        cout << 2*p+2*q << endl;
        if (p > 0 && q > 0)
        for (int i = 0; i < p; i++) {
            cout << "U";
        }
        for (int i = 0; i < q; i++) {
            cout << "L";
        }
        for (int i = 0; i < p; i++) {
            cout << "D";
        }
        for (int i = 0; i < q; i++) {
            cout << "R";
        }
        cout << endl;
    } else if (p == 0 && q > 0) {
        cout << 2 << endl;
        cout << "LR\n";
    } else if (p > 0 && q == 0) {
        cout << 2 << endl;
        cout << "UD\n";
    } else cout << 0 << endl;
    
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