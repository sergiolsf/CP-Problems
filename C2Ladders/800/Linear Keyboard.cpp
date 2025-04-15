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
    string alf; cin >> alf;
    string s; cin >> s;

    vi v(26, 0);
    for (int i = 0; i < 26; i++) {
        v[(int) (alf[i]-'a')] = i+1;
    }

    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
        ans += abs(v[(int) (s[i]-'a')] - v[(int) (s[i-1]-'a')]);
    }

    cout << ans << endl;
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