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

signed main() {
    fastio();
    int n, k; cin >> n >> k;
    int ans = 0;
    
    for (int i = 0; i < 32; i++) {
        if ((1LL << i) & k) ans = (ans + modpow(n, i))%MOD;
    }

    cout << ans << endl;
  
    return 0;
}