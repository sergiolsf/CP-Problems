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
    map<int,int> mp;
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (mp.count(i-a)) ans += mp[i-a];

        if (mp.count(a+i)) mp[a+i]++;
        else mp[a+i] = 1;
    }

    cout << ans << endl;
  
    return 0;
}