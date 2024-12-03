#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const int maxX = 1000005;
const int MOD  = 1e9+7;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int _sieve_size, N, Q;
bitset<maxX> bs;
vi p, V, X, cnt(maxX);

void sieve(int upperbound) {
    _sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < _sieve_size; ++i) if (bs[i]) {
        for (int j = i*i; j < _sieve_size; j += i) bs[j] = 0;
        p.push_back(i);
    }
}

vi primeFactors(int N) {
    vi factors;

    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
        if (N%p[i] == 0) factors.push_back(p[i]);
        while (N%p[i] == 0) {
            N /= p[i];
        }
    }

    if (N != 1) factors.push_back(N);
    return factors;
}

int modPow(int b, int p) {
    if (p == 0) return 1;
    int ans = modPow(b, p/2);
    ans = (ans*ans)%MOD;
    if (p&1) ans = (b*ans)%MOD;
    return ans;
}

signed main() {
    fastio();
    sieve(maxX);

    cin >> N;
    V.resize(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
    }

    cin >> Q;
    X.resize(Q+1);
    for (int i = 1; i <= Q; i++) {
        cin >> X[i];
    }


    /// First Step:
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j*j <= V[i]; j++) {
            if (V[i]%j == 0) {
                cnt[j]++;
                if (V[i]/j != j) cnt[V[i]/j]++;
            }
        }
    }

    /// Second Step:
    for (int i = 1; i <= Q; i++) {
        vi factors = primeFactors(X[i]);
        int sz_factors = factors.size();
        int ans = cnt[1];
        for (int j = 1; j < 1<<sz_factors; j++) {
            int cont = 0, mult = 1;
            for (int k = 0; k < sz_factors; k++) {
                if (1<<k & j) {
                    cont++;
                    mult *= factors[k];
                }
            }
            int sol = cnt[mult];
            if (cont&1) ans -= sol;
            else ans += sol;
        }
        cout << modPow(2, ans) << endl;
    }
    
    return 0;
}