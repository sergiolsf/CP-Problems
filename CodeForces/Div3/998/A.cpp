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
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    int b1 = a1+a2;
    int b2 = a4-a2;
    int b3 = a5-a4;

    if (b1 == b2) {
        if (b2 == b3) {
            cout << 3 << endl;
            return;
        }
        else {
            cout << 2 << endl;
            return;
        }
    }

    if (b1 == b2 || b2 == b3 || b1 == b3) {
        cout << 2 << endl;
        return;
    }

    cout << 1 << endl;
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