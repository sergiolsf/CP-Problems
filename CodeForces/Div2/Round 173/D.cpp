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

int mdc(int a, int b) { return b == 0 ? a : mdc(b , a%b); }

void solve() {
    int l, r, G;
    cin >> l >> r >> G;
    int a = (l-1)/G + 1, b = r/G;

    if (a == 1) {
        cout << a*G << " " << b*G << endl;
        return;
    }

    int i = 0;

    while (i <= b-a) {
        for (int j = 0; j <= i; j++) {
            int k = i-j;
            if (mdc(a+j, b-k) == 1) {
                cout << (a+j)*G << " " << (b-k)*G << endl;
                return;
            }
        }
        i++;
    }

    cout << -1 << " " << -1 << endl;


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