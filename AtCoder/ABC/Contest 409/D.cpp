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
    string s; cin >> s;
    bool mudou = false;
    char a = s[0];
    string ans;
    for (int i = 1; i < n; i++) {
        if ((a <= s[i] && !mudou) || (a == s[i])) {
            ans += a;
            a = s[i];
        } else if (a < s[i] && mudou) {
            ans += a;
            for (int j = i; j < n; j++) {
                ans += s[j];
            }
            cout << ans << endl;
            return;
        } else if (a > s[i] && !mudou) {
            mudou = true;
            ans += s[i];
        } else if (a > s[i] && mudou) {
            ans += s[i];
        }
    }
    ans += a;
    cout << ans << endl;
}

signed main() {
    fastio();
    int t; cin >> t;
    while (t--) {
        solve();
    }
  
    return 0;
}