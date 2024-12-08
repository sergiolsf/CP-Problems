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

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = (ans*ans);
    if (p&1) ans = (b*ans);
    return ans;
}

void perm(int pos, int n, int k) {
    if (n == 1) {
        cout << pos << " ";
        return;
    }
    int cont = 10000000000000;
    if (n <= 45) cont = modpow(2, n-2);
    if (k > cont) {
        perm(pos+1, n-1, k-cont);
        cout << pos << " ";
        return;
    } else {
        cout << pos << " ";
        perm(pos+1, n-1, k);
        return;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (n <= 40 && modpow(2, n-1) < k) {
        cout << -1 << endl;
        return;
    }
    
    perm(1, n, k);
    cout << endl;
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