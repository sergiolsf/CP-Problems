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


signed main() {
    init();

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x]++;
    }

    int ans = 0;
    for (int i = 1; i < MAX_X; i++) {
        int d = 0;
        for (int j = i; j < MAX_X; j+=i) {
            d += v[j];
        }
        ans += mobius[i]*(d*(d-1)/2);
    }

    cout << ans << endl;
    
    return 0;
}