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
    map<int,pii> mp;
    for (int i = 0 ; i < n; i++) {
        int a; cin >> a;
        if (mp.count(a)) mp[a].first++;
        else mp[a] = {0, i};
    }

    int ans = -1;
    for (auto e: mp) {
        if(!e.second.first) ans = e.second.second+1;
    }

    cout << ans << endl;
  
    return 0;
}