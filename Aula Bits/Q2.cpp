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

const int MAX_X = 1'000'005;

vi v(MAX_X);
vi mobius(MAX_X);
vi mfp(MAX_X); // menor fator primo

void init() {
    for (int i = 2; i < MAX_X; i++) {
        for (int j = i; j < MAX_X; j += i) {
            if (!mfp[j]) mfp[j] = i;
        }
    }

    mobius[1] = 1;
    for (int i = 2; i < MAX_X; i++) {
        if (mfp[i/mfp[i]] == mfp[i]) mobius[i] = 0;
        else mobius[i] = -1*mobius[i/mfp[i]];
    }
}

void solve(int teste) {
    int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
    if (b > d) swap(b, d);
    int ans = 0, sub = 0;
    if (k != 0) {
        int n = d/k, m = b/k;
        for (int p = 1; p <= m; p++) {
            sub += mobius[p]*(m/p)*(m/p);
            ans += mobius[p]*(m/p)*(n/p);
        }
        //cout << sub << endl;
        sub = (sub-1)/2;
        ans -= sub;
    }

    cout << "Case " << teste << ": " << ans << endl;
}


signed main() {
    init();

    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }    
    
    return 0;
}