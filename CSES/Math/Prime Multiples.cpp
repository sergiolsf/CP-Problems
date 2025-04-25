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

signed main() {
    fastio();
    int n, k; cin >> n >> k;
    vi a(k);
    for (auto &i: a) cin >> i;

    int ans = 0;
    for (int i = 1; i < (1LL<<k); i++) {
        int mult = n, cont = -1;
        for (int j = 0; j < k; j++) {
            if (i&(1LL<<j)) {
                mult /= a[j];
                cont *= -1;
            }
        }
        //cout << i << " " << cont*mult << endl;
        ans += cont*mult;
    }

    cout << ans << endl;
  
    return 0;
}