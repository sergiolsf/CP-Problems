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
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') cout << 'D';
        else if (s[i] == 'D') cout << 'U';
        else if (s[i] == 'L') cout << 'L';
        else if (s[i] == 'R') cout << 'R';
    }
    cout << endl;
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