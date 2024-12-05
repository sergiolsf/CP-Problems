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

int modpow(int b, int p, int m) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2, m);
    ans = (ans*ans)%m;
    if (p&1) ans = (ans*b)%m;
    return ans;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int d = modpow(b, c, MOD-1);
        cout << modpow(a, d, MOD) << endl;
    }

    return 0;
}