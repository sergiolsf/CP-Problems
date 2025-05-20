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
    int n, x; cin >> n >> x;
    map<int,int> mp;
    vi a(n);
    for (auto &i: a) cin >> i;

    mp[0] = 1;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];

        int y = sum-x;
        ans += mp[y];

        mp[sum]++;
    }

    cout << ans << endl;
  
    return 0;
}