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

const int MAX_N = 1'000'005;

vi v;
vi sieve(MAX_N);

void init() {
    for (int i = 1; i < MAX_N; i++) sieve[i] = 1;
    for (int i = 2; i < MAX_N; i++) {
        if (sieve[i] == 1) {
            for (int j = i; j < MAX_N; j += i) sieve[j] = i;
        }
    }

    for (int i = 1; i < MAX_N; i++) {
        int k = i;
        if (k == sieve[k]) continue;
        set<int> primes;
        while (k != 1) {
            primes.insert(sieve[k]);
            k /= sieve[k];
        }
        if (primes.size() == 2) v.push_back(i);
    }
}

signed main() {
    fastio();
    
    init();

    int q; cin >> q;
    while (q--) {
        int a; cin >> a;
        a = sqrtl(a);
        auto p = upper_bound(all(v), a);
        p--;
        int b = *p;
        cout << b*b << endl;
    }
    return 0;
}