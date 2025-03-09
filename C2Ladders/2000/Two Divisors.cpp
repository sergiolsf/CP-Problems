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

const int MAXN = 10000010;

int sieve[MAXN];

int div (int n) {
        int m = sieve[n];
        int k = 1;
        while (n%m == 0) {
            n/=m;
            k *= m;
        }
    return k;
}

void init() {
    for (int i = 2; i < MAXN; i++) {
        if (sieve[i] == 0) {
            sieve[i] = i;
            for (int j = i*i; j < MAXN; j+=i) {
                if (sieve[j] == 0) sieve[j] = i;
            }
        }
    }
}

signed main() {
    fastio();
    init();
    //cout << sieve[7816968] << endl;

    int n; cin >> n;
    vector<pii> ans(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        int d1 = div(a);
        int d2 = a/d1;
        if (d2 != 1 && __gcd(d1+d2, a) == 1) {
            ans[i] = {d1, d2};
        } else {
            ans[i] = {-1, -1};
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i].first << (i == n-1 ? "\n" : " ");
    } 
    for (int i = 0; i < n; i++) {
        cout << ans[i].second << (i == n-1 ? "\n" : " ");
    }

  
    return 0;
}