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

    map<int,int> mp;
    int ans = 0;
    int ult = 0;
    for (int i = 0; i < n; i++) {
        if (mp.count(a[i])) {
            int u = mp[a[i]]+1;
            if (u > ult) ult = u;
        }
        ans = max(ans, i-ult+1);
        mp[a[i]] = i;
    }

    cout << ans << endl;
  
    return 0;
}