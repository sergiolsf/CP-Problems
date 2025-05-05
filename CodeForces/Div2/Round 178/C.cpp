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

void g(string a) {
    cout << a << endl;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    if (s[0] == s[n-1] || s[n-1] == s[n-2]) {
        if (s[n-1] == 'B') g("Bob");
        else g("Alice");
        return;
    }
    int A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') A++;
        else B++;
    }
    if (s[n-1] == 'B' && B > 1) {
        g("Bob");
        return;
    }
    if (s[0] == 'B' && B > 1) {
        g("Bob");
        return;
    }
    if (s[0] == 'B' && n == 2) {
        g("Bob");
        return;
    }
    g("Alice");
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