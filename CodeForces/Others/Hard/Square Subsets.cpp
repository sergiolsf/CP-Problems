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

const int MOD = 1e9+7;
vi num(70);

int mod(int a) {
    return (a%MOD+MOD)%MOD;
}

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = mod(ans*ans);
    if (p&1) ans = mod(ans*b);
    return ans;
}

int primos(int p) {
    int ans = 0;
    for (int i = 2; i <= 70; i++) {
        int c = 0;
        while (p%i == 0) {
            c++;
            p /= i;
        }
        if (c&1) {
            ans |= (1LL << num[i]);
        }
    }
    return ans;
}

bool P(int p) {
    for (int i = 2; i*i <= p; i++) {
        if (p%i == 0) return false;
    }
    return true;
}

void init() {
    int cont = 0;
    for (int i = 2; i < 70; i++) {
        if (P(i)) {
            num[i] = cont;
            cont++;
        }
    }
}

signed main() {
    fastio();
    init();
    int n; cin >> n;
    vi X;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        int m = primos(a);
        if (m) X.push_back(m);
    }

    vi basis;

    for (auto e: X) {
        //cout << e << endl;
        int b = e;
        for (auto i: basis) {
            b = min(b, b^i);
        }
        if (b) basis.push_back(b);
    }

    int nulti = n-basis.size();

    cout << mod(modpow(2, nulti)-1) << endl;
  
    return 0;
}