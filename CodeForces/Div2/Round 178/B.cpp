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

void solve() {
    int n; cin >> n;
    vi a(n);
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (mp.count(a[i])) mp[a[i]]++;
        else mp[a[i]] = 1;
    }
    int sumfix = 0;
    vi ans;
    int p = 0;
    for (int i = n-1; i >= 0; i--) {
        p = (--mp.end())->first;
        ans.push_back(sumfix+p);
        sumfix += a[i];
        mp[a[i]]--;
        if (mp[a[i]] == 0) mp.erase(a[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n-1 ? "\n" : " ");
    }
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}