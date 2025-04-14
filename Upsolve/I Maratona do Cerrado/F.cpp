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

const int MOD = 5;

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

signed main() {
    fastio();
    int n; cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int u = (2*3*4)%MOD;
    int ans = 1, val = 0;

    while (n) {
        val += n/5;
        ans = (ans*modpow(u, n/5))%MOD;
        int r = n%5;
        for (int i = 2; i <= r; i++) {
            ans = (ans*i)%MOD;
        }
        n /= 5;
    }

    int i2 = inv(2);
    ans = (ans*modpow(i2, val))%MOD;

    if (ans&1) ans += 5;

    cout << ans << endl;

    return 0;
}