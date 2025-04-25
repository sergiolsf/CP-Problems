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

int inv (int a) {
    return modpow(a, MOD-2);
}

signed main() {
    fastio();
    int n; cin >> n;
    int sum = 1, num = 1, prod = 1, num1 = 1;

    vector<pii> v(n);
    for (int i = 0; i < n; i++) {
        int x, k; cin >> x >> k;
        v[i] = {x, k};
        num = (num*(k+1))%MOD;
        num1 = (num1*(k+1));
        if (i == 0) num1 = (num1-)/2;
        num1 = num1%(MOD-1);
    }

    for (auto e: v) {
        int x = e.first, k = e.second;
        int num = ((modpow(x, k+1)-1)%MOD + MOD)%MOD;
        int den = inv(x-1);
        sum = (sum*((num*den)%MOD))%MOD;
    }

    int p = 1;
    for (auto e: v) {
        int x = e.first, k = e.second;
        p = (p*modpow(x, k))%(MOD);
    }

    prod = modpow(p, num1);

    cout << num << " " << sum << " " << prod << endl;
  
    return 0;
}