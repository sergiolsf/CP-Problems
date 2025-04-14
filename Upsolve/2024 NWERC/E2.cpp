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

int MOD;

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = (ans*ans)%MOD;
    if (p&1) ans = (ans*b)%MOD;
    return ans;
}

signed main () {
    fastio();
    int n, k; cin >> n >> k;
    string s; cin >> s;

    MOD = n;

    for (int i = 0; i < n; i++) {
        int m = (i*modpow(2, k))%MOD;
        cout << s[m];
    }    

    cout << endl;
    
    return 0;
}