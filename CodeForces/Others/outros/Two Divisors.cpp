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

int lcm(int a, int b) {
     return a/__gcd(a,b) * b;
}

int menorDiv(int m) {
    for (int i = 2; i*i <= m; i++) {
        if (m%i == 0) return i;
    }
}

void solve() {
    int a, b; cin >> a >> b;
    int mi = min(a,b);
    int ma = max(a,b);
    int m = lcm(a,b);

    if (ma == m) {
        if (mi == 1) m*=m;
        else {
            m *= menorDiv(m);
        }
    }

    cout << m << endl;
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