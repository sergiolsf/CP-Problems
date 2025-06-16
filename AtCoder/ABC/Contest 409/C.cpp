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
    int n, l; cin >> n >> l;
    int ant = 0;
    map<int,int> mp;
    mp[0] = 1;
    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        ant = (ant+a)%l;
        mp[ant]++;
    }

    if (l%3) {
        cout << 0 << endl;
        return 0;
    }

    int d = l/3;
    int ans = 0;
    for (int i = 0; i < l; i++) {
        int a = 0, b = 0, c = 0;
        if (mp.count(i)) a = mp[i];
        if (mp.count(i+d)) b = mp[i+d];
        if (mp.count(i+2*d)) c = mp[i+2*d];
        ans += a*b*c;
    }

    cout << ans << endl;
  
    return 0;
}