#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MOD = 1e9+7;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int modpow(int b, int p) {
    b %= MOD;
    int ans = 1;
    while (p > 0) {
        if (p&1) ans = (ans*b)%MOD;
        b = (b*b)%MOD;
        p >>= 1;
    }
    return ans;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << modpow(a,b) << endl;
    }
    return 0;
}