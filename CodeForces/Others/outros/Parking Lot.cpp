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

int modpow(int b, int p) {
    int ans = 1;
    while (p > 0) {
        if (p&1) ans *= b;
        b = b*b;
        p >>= 1;
    }
    return ans;
}

signed main() {
    fastio();
    int n; cin >> n;

    int ans = 2*4*3*modpow(4, n-3) + (n-3)*9*4*modpow(4, n-4);

    cout << ans << endl;
  
    return 0;
}