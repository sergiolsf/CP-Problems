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

const int MOD = 1'000'000'007;

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = (ans*ans)%MOD;
    if (p&1) ans = (ans*b)%MOD;
    return ans;
}

int inv(int a) {
    return modpow(a, MOD-2);
}

void solve() {
    int n, x; cin >> n >> x;
    if (n-x > 364) {
        cout << 0 << endl;
        return;
    }

    int ans = 1;
    for (int i = n; i > x; i--) {
        ans = (ans*(i%MOD))%MOD;
    }
    int f = 1;
    int k = n-x;
    for (int i = 1; i <= k; i++) f = (f*i)%MOD;
    ans = (ans*inv(f))%MOD;

    for (int i = 364; i > 364-k; i--) {
        ans = (ans*i)%MOD;
    }


    ans = (ans*inv(modpow(365, n-1)))%MOD;
    


    cout << ans << endl;
}

signed main() {
    fastio();
    int t; cin >> t;
    while (t--) {
        solve();
    }  
    return 0;
}