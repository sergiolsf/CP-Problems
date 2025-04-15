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
    if (n >= 3) {
        cout << "NO\n";
        return;
    }
    if (n == 1) {
        cout << "YES\n";
        return;
    }
    if (s[0] == s[1]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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