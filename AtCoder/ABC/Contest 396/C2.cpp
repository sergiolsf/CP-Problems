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
    int n; cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;

    vi L(n+1, 0), R(n+1, 0);
    int l = 0, r = 0;

    for (auto i: a) {
        if (!R[i]) r++;
        R[i]++;
    }

    int ans = 0;
    for (auto i: a) {
        R[i]--;
        if (!R[i]) r--;
        if (!L[i]) l++;
        L[i]++;

        ans = max(ans, l+r);
    }

    cout << ans << endl;
  
    return 0;
}