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
    int n;
    cin >> n;

    if(n == 3) {
        cout << "! 1 2 3" << endl;
        cout.flush();
        return;
    }

    int i = 1, j = 2, k = 3;
    for (int m = 0; m < 75; m++) {
        cout << "? " << i << " " << j << " " << k << endl;
        cout.flush();
        int r;
        cin >> r;

        if(r == 0) {
            cout << "! " << i << " " << j << " " << k << endl;
            cout.flush();
            return;
        }

        int p = r;
        cout << "? " << i << " " << j << " " << p << endl;
        cout.flush();
        cin >> r;
        
        if(r == 0) {
            cout << "! " << i << " " << j << " " << p << endl;
            cout.flush();
            return;
        }

        int a = r;
        cout << "? " << j << " " << k << " " << p << endl;
        cout.flush();
        cin >> r;
        
        if(r == 0) {
            cout << "! " << j << " " << k << " " << p << endl;
            cout.flush();
            return;
        }

        int b = r;
        cout << "? " << i << " " << k << " " << p << endl;
        cout.flush();
        cin >> r;
        
        if(r == 0) {
            cout << "! " << i << " " << k << " " << p << endl;
            cout.flush();
            return;
        }

        i = a;
        j = b;
        k = r;
    }

    cout << "! " << i << " " << j << " " << k << endl;
    cout.flush();
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
