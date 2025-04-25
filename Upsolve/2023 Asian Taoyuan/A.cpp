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
    string s; cin >> s;
    int ans = 0;
    int sz = s.size();
    int sinal = 1;
    for (int i = sz-1; i >= 0; i -= 3) {
        int d = 1;
        int num = 0;
        for (int j = i, cnt = 1; j >= 0 && cnt <= 3; cnt++, j--) {
            int p = s[j]-'0';
            num += p*d;
            d *= 10;
        }
        ans += sinal*num;
        sinal *= -1;
    }

    ans = abs(ans);
    cout << ans;
    if (ans%13) cout << " NO\n";
    else cout << " YES\n";
}

signed main() {
    fastio();
    int t; cin >> t;
    while(t--) {
        solve();
    }
  
    return 0;
}