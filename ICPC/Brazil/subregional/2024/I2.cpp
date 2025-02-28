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

#define MAXN 100010
#define MAXV 1000010
const int MOD = 1e9+7;

bool pr[MAXV];
int fator[MAXV];
int cnt[MAXV];
int pot2[MAXN];

signed main() {
    fastio();

    /// pre calculo crivo
    for (int i = 1; i < MAXV; i++) pr[i] = true;
    pr[1] = false;
    fator[1] = 1;
    for (int i = 2; i < MAXV; i++) {
        if (pr[i]) {
            fator[i] = i;
            for (int j = i*i; j < MAXV; j += i) {
                pr[j] = false;
                fator[j] = i;
            }
        }
    }
    ///

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        for (int j = 1; j*j <= v; j++) {
            if (v%j == 0) {
                cnt[j]++;
                if (v/j != j) cnt[v/j]++;
            }
        }

    }
    pot2[0] = 1;
    for (int i = 1; i <= n; i++) pot2[i] = (pot2[i-1]*2)%MOD;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int ans = cnt[1];
        vi prime;
        while (x > 1) {
            prime.pb(fator[x]);
            int fat = fator[x];
            while (x%fat == 0) x /= fat;
        }
        int sz = prime.size();
        for (int j = 1; j < (1<<sz); j++) {
            int prod = 1;
            int neg = 0;
            for (int k = 0; k < sz; k++) {
                if (j & ((1<<k))) {
                    prod *= prime[k];
                    neg++;
                }
            }
            if (neg%2 == 0) ans += cnt[prod];
            else ans -= cnt[prod];
        }

        cout << pot2[ans] << endl;
    }
  
    return 0;
}