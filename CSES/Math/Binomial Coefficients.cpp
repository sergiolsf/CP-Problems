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

vi fat(1e6+5);
vi inv(1e6+5);

const int MOD = 1e9+7;

int modPow(int b, int p) {
    if (p == 0) return 1;
    int ans = modPow(b, p/2);
    ans = (ans*ans)%MOD;
    if (p&1) ans = (ans*b)%MOD;
    return ans;
}

int bin (int a, int b) {
    int ans = (fat[a]*inv[b])%MOD;
    ans = (ans*inv[a-b])%MOD;
    return ans;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << bin(a, b) << endl;
}

signed main() {
    fastio();

    fat[0] = 1;
    inv[0] = modPow(fat[0], MOD-2);
    for (int i = 1; i <= 1e6; i++) {
        fat[i] = (fat[i-1]*i)%MOD;
        inv[i] = modPow(fat[i], MOD-2);
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }    
    return 0;
}