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
    int cima = 0, baixo = 0, ans = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cima += i;
            baixo += n-i-1;
            ans = max({ans, baixo, cima});
            flag = false;
        } else {
            if (flag) {
                baixo = 0; cima = 1;
            } else {
                cima = baixo+1;
                baixo = 0;
            }
            ans = max({ans, baixo, cima});
            flag = true;
        }
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