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
    for (int i = 1; i < n; i++) {
        if (s[i] == 'a' && s[i-1] == 'b') {
            cout << i << " " << i+1 << endl;
            return;
        }
        if (s[i-1] == 'a' && s[i] == 'b') {
            cout << i << " " << i+1 << endl;
            return;
        }
    }
    cout << "-1 -1\n";
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