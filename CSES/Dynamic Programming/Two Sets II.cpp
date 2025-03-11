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

const int MAXN = 510;
const int MAXS = 100'000;
const int MOD = 1e9+7;

int esperado;
int n; 
vvi memo(MAXN+1, vi(MAXS+1, -1));

int dp(int i, int sum) {
    if (sum > esperado) return 0;
    if (i == n+1) {
        if (sum == esperado) return 1;
        return 0;
    }
    int &ans = memo[i][sum];
    if (ans != -1) return ans;
    return ans = (dp(i+1, sum+i) + dp(i+1, sum))%MOD;
}

int modpow(int b, int p) {
    b%=MOD;
    int ans = 1;
    while (p > 0) {
        if (p&1) ans = (ans*b)%MOD;
        b = (b*b)%MOD;
        p >>= 1;
    }
    return ans;
}

int inv(int a) {
    return modpow(a, MOD-2);
}

signed main() {
    fastio();
    cin >> n;
    esperado = ((n+1)*n)/2;
    if (esperado&1) {
        cout << 0 << endl;
        return 0;
    } else {
        esperado /= 2;
        cout << (dp(1, 0)*inv(2))%MOD << endl;
    }
  
    return 0;
}