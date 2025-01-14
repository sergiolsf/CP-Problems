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

int pow(int b, int p) {
    if (p == 0) return 1;
    int ans = pow(b, p/2);
    ans = ans*ans;

    if (p&1) ans *= b;

    return ans;
}

void solve() {
    int n;
    cin >> n;

    int cont = 0;

    while (n > 3) {
        cont++;
        n /= 4;
    }

    if (cont == 0) cout << 1 << endl;
    else cout << (int) pow(2, cont) << endl;
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