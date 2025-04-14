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

const int MAX_B = 62;

signed main() {
    fastio();
    int n; cin >> n;

    int pot = 2;
    int ans = 0;
    for (int i = 1; i < MAX_B; i++) {
        if (pot > n) break;

        int lo = 0, hi = sqrtl(n/pot)+1;
        while (hi-lo > 1) {
            int m = (hi+lo)/2;
            if ((pot * m * m) <= n) lo = m;
            else hi = m;
        }

        ans += (lo+1)/2;
        pot = pot*2LL;
    }

    cout << ans << endl;
  
    return 0;
}