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

int MAX_X;;

vi v;
vi mobius;
vi mfp; // menor fator primo

void init() {
    for (int i = 2; i < MAX_X; i++) {
        if (mfp[i]) continue;
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
    int n; cin >> n;
    
    MAX_X = n+1;
    v.resize(MAX_X);
    mobius.resize(MAX_X);
    mfp.resize(MAX_X, 0);
    init();


    int t = n*(n+1)/2;
    int v = 0;
    for (int i = 1; i <= n; i++) {
        v += mobius[i]*((n/i)*(n/i + 1)/2);
    }

    int ans = 6*(t-v);

    cout << ans << endl;
    
    return 0;
}